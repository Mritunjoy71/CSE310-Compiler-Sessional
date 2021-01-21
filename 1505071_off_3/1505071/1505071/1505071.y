%{
#include<bits/stdc++.h>
#include "SymTable.h"
using namespace std;

string variable_type;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
int IDparameters = 0;
SymbolTable *table=new SymbolTable(13);
bool funcDef = false;
extern int line_no;
int errors=0;
vector<SymbolInfo*> params; 
vector<string> parameters; 

ofstream log_file, error_file;
extern string pp;
SymbolInfo *stmts=new SymbolInfo();
int nullp=0;

void yyerror(const char *s)
{
	//write your code
}

%}
%union{
SymbolInfo* symVal;
}

%token  IF ELSE FOR WHILE DO BREAK CONTINUE INT FLOAT CHAR DOUBLE VOID RETURN SWITCH CASE DEFAULT INCOP DECOP ASSIGNOP LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD SEMICOLON COMMA STRING NOT PRINTLN 
%token <symVal>ID 
%token <symVal>CONST_INT 
%token <symVal>CONST_FLOAT 
%token <symVal>CONST_CHAR 
%token <symVal>ADDOP
%token <symVal>MULOP
%token <symVal>LOGICOP
%token <symVal>RELOP

%type <symVal>type_specifier expression logic_expression rel_expression simple_expression term unary_expression factor variable expression_statement statement compound_statement  declaration_list var_declaration statements func_declaration  func_definition parameter_list unit program arguments argument_list

%nonassoc second_precedence
%nonassoc ELSE 
%error-verbose


%%
start : program {
		            log_file << "Line " << line_no << " : start : program\n"<< endl;
		            log_file<<pp<<endl;
		            
		        }
    ; 

program : program unit {
			                log_file << "Line " << line_no << " : program : program unit\n"<< endl;
			                $$->match= $1->match+"\n" + $2->match;
				            log_file<<$$->match<<endl;
			           } 
	| unit  {	
			    log_file << "Line " << line_no << " : program : unit\n"<< endl;
			    $$->match= $1->match;
				log_file<<$$->match<<endl;
			    
	        }
	;
	
unit : var_declaration {
			                log_file << "Line " << line_no << " : unit : var_declaration\n"<< endl;
			                $$->match= $1->match;
				            log_file<<$$->match<<endl;
	                	}
     | func_declaration {
			                log_file << "Line " << line_no << " : unit : func_declaration\n"<< endl;
			                $$->match= $1->match;
				            log_file<<$$->match<<endl;
                    	}
     | func_definition {
			                log_file << "Line " << line_no << " : unit : func_definition\n"<< endl;
			                $$->match= $1->match ;
				            log_file<<$$->match<<endl;
     	                }
     ;
     
func_declaration : 	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
					{
						log_file << "Line " << line_no << " : func_declaration : 	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n"; 
						SymbolInfo *temp = table->lookUp($2->Name);
						if(temp != NULL){
							error_file << "Error at line " << line_no << " Function "<< $2->Name <<" already declared" << endl << endl;
							errors++;
						}else {
							SymbolInfo* temp2 = table->InsertandGet($2->Name, "ID");
							temp2->IDType="FUNC";
							temp2->FuncRet=$1->VarType;
							for(int i = 0; i<parameters.size(); i++){
								temp2->ParameterList.push_back(parameters[i]);					
							}
							parameters.clear();
						}
						
						$$->match= $1->match+ $2->Name +" ("+$4->match+" )" +" ;" ;
						log_file<<$$->match<<endl;
					}
					| type_specifier ID LPAREN RPAREN SEMICOLON
					{
						log_file << "Line " << line_no << " : func_declaration : 	type_specifier ID LPAREN RPAREN SEMICOLON\n"; 
						SymbolInfo *temp = table->lookUp($2->Name);
						if(temp != NULL){
							error_file << "Error at line " << line_no << " Function "<< $2->Name <<" already declared" << endl << endl;
							errors++;
						}else {
							SymbolInfo* temp2 = table->InsertandGet($2->Name, "ID");
							temp2->IDType="FUNC";
							temp2->FuncRet=$1->VarType;
						}
						
						$$->match= $1->match+ $2->Name +" ("+" )" +" ;" ;
						log_file<<$$->match<<endl;
					}
		 			;
		 
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
				{
				log_file << "Line " << line_no << " : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
				SymbolInfo *temp = table->lookUp($2->Name);
				if(parameters.size() != IDparameters){
					error_file << "Error at line " << line_no << " Parameter mismatch for Function "<< $2->Name << endl << endl;
					parameters.clear(); IDparameters = 0;
					errors++;
				}												
				if(temp != NULL){
					if(temp->FuncDefined== true){
						error_file << "Error at line " << line_no << "Function "<< $2->Name <<" already defined" << endl << endl;
						errors++;
						parameters.clear();
						IDparameters = 0;
					}
					else if(temp->FuncRet != $1->VarType){
						error_file << "Error at line " << line_no << "Function "<< $2->Name <<" :return type doesn't match declaration" << endl << endl;
						errors++;
						parameters.clear();
						IDparameters = 0; 
					} 
					else if(temp->ParameterList.size() != parameters.size()){
						error_file << "Error at line " << line_no << "Function "<< $2->Name <<" :Parameter list doesn not match declaration" << endl << endl;
						parameters.clear();
						IDparameters = 0;
						errors++;					
					}
					else{
						for(int i = 0; i<temp->ParameterList.size(); i++){
							if(temp->ParameterList[i] != parameters[i]){
								error_file << "Error at line " << line_no << "Function "<< $2->Name<< " :argument mismatch" << endl << endl;
								parameters.clear();
								IDparameters = 0;
								errors++;	
							}
						}				
					}
				}
				else{
					SymbolInfo* temp = new SymbolInfo();
					temp = table->InsertandGet($2->Name, "ID");
					temp->IDType="FUNC";
					temp->FuncRet=$1->VarType;
					for(int i = 0; i<parameters.size(); i++){
						temp->ParameterList.push_back(parameters[i]);					
					}
					temp->FuncDefined=true;
				}
				parameters.clear();
				IDparameters = 0;
				$$->match= $1->match +$2->Name+" (" +$4->match+") " + "\n" +$6->match;
				log_file<<$$->match<<endl;
				}
				
				| type_specifier ID LPAREN RPAREN compound_statement 
				{ 
				    log_file << "Line " << line_no << " : func_definition : type_specifier ID LPAREN RPAREN compound_statement\n";
				    SymbolInfo *temp = table->lookUp($2->Name);
				    if(temp != NULL){
					    if(temp->FuncDefined== true){
						    error_file << "Error at line " << line_no << "Function "<< $2->Name <<" already defined" << endl << endl;
						    errors++;
					    }
					    else if(temp->FuncRet != $1->VarType){
						    error_file << "Error at line " << line_no << "Function "<< $2->Name <<" :return type doesn't match declaration" << endl << endl;
						    errors++;
					    } 					    
				    }
				    else{
					    SymbolInfo* temp = new SymbolInfo();
					    temp = table->InsertandGet($2->Name, "ID");
					    temp->IDType="FUNC";
					    temp->FuncRet=$1->VarType;
					    temp->FuncDefined=true;
				    }
				    $$->match= $1->match +$2->Name+" ("+") " + "\n" +$5->match;
				    log_file<<$$->match<<endl;
				}
				
 		 		;
 		 			


 		 
parameter_list  : parameter_list COMMA type_specifier ID
				{
					log_file << "Line " << line_no << " : parameter_list  : parameter_list COMMA type_specifier ID\n";
					parameters.push_back($3->VarType);
					IDparameters++;
					$4->IDType="VAR";
					$4->setVarType($3->VarType);
					SymbolInfo* temp = new SymbolInfo($4->Name, $4->Type);
					temp->IDType="VAR";
					
					params.push_back(temp);
					
					$$->match= $1->match +","+$3->match + $4->Name;
				    log_file<<$$->match<<endl;
				
				} 
 				| parameter_list COMMA type_specifier	
				{					
					log_file << "Line " << line_no << " : parameter_list  : parameter_list COMMA type_specifier\n"<< endl;
					parameters.push_back($3->VarType);
					$$->match= $1->match +","+$3->match;
				    log_file<<$$->match<<endl;
				}
 				| type_specifier ID
				{
					log_file << "Line " << line_no << " : parameter_list  : type_specifier ID\n";
					parameters.push_back($1->VarType);
					IDparameters++;
					$2->IDType="VAR";
					$2->setVarType($1->VarType);
					params.push_back($2);
					
					$$->match= $1->match + $2->Name ;
				    log_file<<$$->match<<endl;
				}
 				| type_specifier
				{
					log_file << "Line " << line_no << " : parameter_list  : type_specifier\n"<< endl;
					parameters.push_back($1->VarType);				
					$$->match= $1->match ;
				    log_file<<$$->match<<endl;
				}
				
 				;
compound_statement : 	LCURL 
						{
							table->enterScope(); 
							for(int i = 0; i<params.size(); i++) table->Insert(params[i]);
							params.clear();
						} statements {table->printAll(log_file);}RCURL{table->exitScope();}
						{
							log_file << "Line " << line_no << " : compound_statement : LCURL statements RCURL\n"<< endl;
							$$->match= "{\n" +stmts->match + "}" ;
						    log_file<<$$->match<<endl;
						}
 		    			| LCURL RCURL
 		    			{
 		    			    log_file << "Line " << line_no << " : compound_statement : LCURL RCURL\n"<< endl;
 		    			    table->enterScope(); 
							for(int i = 0; i<params.size(); i++) table->Insert(params[i]);
							
							table->printAll(log_file);
							
							params.clear();
							
							table->exitScope();
							
                            $$->match="{ }";
						    log_file<<$$->match<<endl;		    			
 		    			}
 		    			;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
                {
                    log_file << "Line " << line_no << " : var_declaration : type_specifier declaration_list SEMICOLON\n"<< endl;
                    $$->match=$1->match+$2->match+";";
				    log_file<<$$->match<<endl;
                    
                }	 		
				;
 		 
type_specifier	: INT
				{
					log_file << "Line " << line_no << " : type_specifier	: INT\n"<< endl; 
					SymbolInfo* s= new SymbolInfo("INT");
					s->setVarType("INT");
					variable_type = "INT";
					$$ = s;
					$$->match="int ";
					log_file <<$$->match<< endl;
				}
 				| FLOAT
				{	
					log_file << "Line " << line_no << " : type_specifier	: FLOAT\n"<< endl;
					SymbolInfo* s= new SymbolInfo("FLOAT");
					s->setVarType("INT");
					variable_type = "FLOAT";
					$$ = s;
					$$->match="float ";
					log_file <<$$->match<< endl;
				}
 				| VOID
				{
					log_file << "Line " << line_no << " : type_specifier	: VOID\n"<< endl;
					SymbolInfo* s= new SymbolInfo("VOID");
					s->setVarType("INT");
					variable_type = "VOID";
					$$ = s;
					$$->match="void ";
					log_file <<$$->match<< endl;
				}
 				;
 		
 		
declaration_list : 	declaration_list COMMA ID
					{
						log_file << "Line " << line_no << " : declaration_list : 	declaration_list COMMA ID\n";
						if(variable_type == "VOID"){
							error_file << "Error at line " << line_no << " :variable type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* temp = table->curScope->lookUp($3->Name);
							if(temp != NULL){
							    error_file << "Error at line " << line_no << ": Multiple Declaration of "<< $3->Name << endl << endl;	
								errors++;	
							}
							else{
								SymbolInfo* temp2 = new SymbolInfo($3->Name, $3->Type);
								temp2->setVarType(variable_type);
								temp2->IDType="VAR";
								table->Insert(temp2);
							}
						}
						$$->match=$1->match+","+$3->Name;
						log_file<<$$->match<<endl;
					}
 					| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
					{
						log_file << "Line " << line_no << " : declaration_list : 	declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n";
						if(variable_type == "VOID"){
							error_file << "Error at line " << line_no << " : array type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* temp = table->curScope->lookUp($3->Name);
							if(temp!= NULL){
							    error_file << "Error at line " << line_no << " : Multiple Declaration of  " << $3->Name << endl << endl;
								errors++;			
							}
							else{
								SymbolInfo* temp2 = new SymbolInfo($3->Name, $3->Type);
								temp2->setVarType(variable_type);
								temp2->IDType="ARA";
								int araSize = atoi(($5->Name).c_str());
								temp2->AraSize=araSize;
								
								table->Insert(temp2);						
							}
						}
						$$->match=$1->match+","+$3->Name+"["+$5->Name+"]";
						log_file<<$$->match<<endl;

					}
 					| ID
					{
						log_file << "Line " << line_no << " : declaration_list :	ID\n";
						if(variable_type == "VOID"){
							error_file << "Error at line " << line_no << " :variable type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* temp = table->curScope->lookUp($1->Name);   
							if(temp!= NULL){
							    error_file << "Error at line " << line_no << ": Multiple Declaration of "<< $1->Name << endl << endl;	
								errors++;		
							}
							else{
								SymbolInfo* temp2 = new SymbolInfo($1->Name, $1->Type);
								temp2->setVarType(variable_type);
								temp2->IDType="VAR";
								table->Insert(temp2);
							}
						}
						$$->match=$1->Name;
						log_file<<$$->match<<endl;
					}
					| ID LTHIRD CONST_INT RTHIRD
					{
						log_file << "Line " << line_no << " : declaration_list :	ID LTHIRD CONST_INT RTHIRD\n";
						if(variable_type == "VOID"){
							error_file << "Error at line " << line_no << " :array type can't be void" << endl << endl;
							errors++;
						}
						else{
						   
							SymbolInfo* temp = table->curScope->lookUp($1->Name);
							if(temp!= NULL){
								error_file << "Error at line " << line_no << ": Multiple Declaration of "<< $1->Name << endl << endl;	
								errors++;
							}
							else{
								SymbolInfo* temp2 = new SymbolInfo($1->Name, $1->Type);
								temp2->setVarType(variable_type);
								temp2->IDType="ARA";
								int araSize = atoi(($3->Name).c_str());
								temp2->AraSize=araSize;
								table->Insert(temp2);
							}
						}
						$$->match=$1->Name+"["+$3->Name+"]";
						log_file<<$$->match<<endl;
					}						
					;
 		  
statements : statement
       {
           log_file << "Line " << line_no << " : statements : statement\n"<< endl;
           $$->match=$1->match+"\n";
		   log_file<<$$->match<<endl;   
		   stmts->match=$$->match;
                  
       }
	   | statements statement
	   {    
	       log_file << "Line " << line_no << " : statements : statements statement\n"<< endl;
           $$->match=$1->match+"\n"+$2->match+"\n";
		   log_file<<$$->match<<endl;   
		   stmts->match=$$->match;
	   }
	   ;
	   
statement : var_declaration
      {
          log_file << "Line " << line_no << " : statement : var_declaration\n"<< endl;
          $$->match=$1->match;
		  log_file<<$$->match<<endl;       
     }
	  | expression_statement
	  {
	      log_file << "Line " << line_no << " : statement : expression_statement\n"<< endl;
	      $$->match=$1->match;
	      log_file<<$$->match<<endl;
	     
	  
	  }
	  | compound_statement
	  {
	      log_file << "Line " << line_no << " : statement : compound_statement\n"<< endl;
	      $$->match=$1->match;
		  log_file<<$$->match<<endl;
	  }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	  {
	      log_file << "Line " << line_no << " : statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<< endl;
	      $$->match="for(" + $3->match+ $4->match+$5->match+" )"+$7->match;
		  log_file<<$$->match<<endl;
	      
	      
	  }
	  | IF LPAREN expression RPAREN statement %prec second_precedence
	  { 
	      log_file << "Line " << line_no << " : statement : IF LPAREN expression RPAREN statement\n"<< endl;
	      $$->match="if("+$3->match+" )"+$5->match;
	      log_file<<$$->match<<endl;
	  } 
	  | IF LPAREN expression RPAREN statement ELSE statement 
	  {
	      log_file << "Line " << line_no << " : statement : IF LPAREN expression RPAREN statement ELSE statement\n"<< endl;
	      $$->match="if("+$3->match+" )"+$5->match+"else"+$7->match;
	      log_file<<$$->match<<endl;
	   }
	  | WHILE LPAREN expression RPAREN statement
	  { 
	      log_file << "Line " << line_no << " : statement : WHILE LPAREN expression RPAREN statement\n"<< endl;
	      $$->match="while("+$3->match+" )"+$5->match;
	      log_file<<$$->match<<endl;
	  }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  { 
	      log_file << "Line " << line_no << " : statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<< endl;
	      $$->match="println("+$3->match+" )"+";";
	      log_file<<$$->match<<endl;
	  }		 		
	  | RETURN expression SEMICOLON
	  {
	      log_file << "Line " << line_no << " : statement : RETURN expression SEMICOLON\n"<< endl;
	      $$->match="return "+$2->match + ";";
	      log_file<<$$->match<<endl;
	  }		 			
	  ;
	  
	  
expression_statement 	: SEMICOLON
                        {
                            log_file << "Line " << line_no << " : expression_statement : SEMICOLON\n"<< endl;
                            $$->match=";";
		                    log_file << $$->match << endl; 
                        
                        }			
						| expression SEMICOLON 
						{
						    log_file << "Line " << line_no << " : expression_statement : expression SEMICOLON\n"<< endl;
						    $$->match=$1->match+";";
						    log_file<<$$->match<<endl;
						}	 		
						;
	  
	  
variable : 	ID
			{
				log_file << "Line " << line_no << " : variable : ID\n";
				SymbolInfo* temp = table->lookUpVar($1->Name,"VAR");
				if(temp == NULL){
					error_file << "Error at line " << line_no << " : " << $1->Name << " doesn't exist" <<  endl;					
					errors++;
					nullp=1;
				}
				else{
					$$ = temp;
				}	
				
				$$->match=$1->Name;
		        log_file << $$->match << endl; 		
			} 		
	 		| ID LTHIRD expression RTHIRD
			{
				log_file << "Line " << line_no << " : variable : ID LTHIRD expression RTHIRD\n";
				SymbolInfo* temp = table->lookUpVar($1->Name,"ARA");
				if(temp == NULL){
				    error_file << "Error at line " << line_no << " : " <<$1->Name << " doesn't exist"<< endl;					
					errors++;
					nullp=1;				
				}
				else{
					if($3->VarType=="INT"){
					
					    if($3->val >= temp->AraSize){
				            error_file << "Error at line " << line_no << " : " <<$1->Name << " array index out of bounds" <<  endl << endl;				
						    errors++;
					    } 
					    $$ = temp;
				}
				else{
				    error_file << "Error at line " << line_no << " : " <<$1->Name << " Non-integer Array Index " <<  endl << endl;				
				   errors++; 
   				}
				
				}
				$$->match=$1->Name+"["+$3->match+"]";
		        log_file << $$->match << endl; 			
			} 
	 		;
	 
	 
expression : logic_expression	
			{
				log_file << "Line " << line_no << " : expression : logic_expression\n"<< endl;
				$$ = $1;
				$$->match=$1->match;
		        log_file << $$->match << endl; 
			}
	   		| variable ASSIGNOP logic_expression
			{
				log_file << "Line " << line_no << " : expression : variable ASSIGNOP logic_expression\n"<< endl;
				if(nullp==1)
				{   
				    error_file << "Type mismatch" <<endl << endl;
				    nullp=0;
				    
				}
				else{
				    string vType = $1->VarType;
				    if($1->VarType == "INT" && $3->VarType=="FLOAT"){
				        error_file << "error at line " << line_no <<" : Assigning float value to integer"<<endl << endl;
					    errors++;
				    }
				    else if($1->VarType == "FLOAT" && $3->VarType=="INT"){
				        error_file << "error at line " << line_no <<" : Assigning integer value to float"<<endl << endl;
					    errors++;
				    }
			    }
				$$ = $1;
				$$->match=$1->match+"="+$3->match;
		        log_file << $$->match << endl; 							
			} 	
	   		;
			
logic_expression 	: rel_expression
					{
						log_file << "Line " << line_no << " : logic_expression : rel_expression\n"<< endl;
						$$ = $1; 
						$$->match=$1->match;
		                log_file << $$->match << endl; 
					} 	
		 			| rel_expression LOGICOP rel_expression
					{
						log_file << "Line " << line_no << " : logic_expression : rel_expression LOGICOP rel_expression\n"<< endl;
						SymbolInfo* temp = new SymbolInfo("INT");
						$$ = temp;	
						$$->match=$1->match+$2->Name+$3->match;
		                log_file << $$->match << endl; 
					} 	
		 			;

rel_expression	: simple_expression 
				{
					log_file << "Line " << line_no << " : rel_expression : simple_expression\n"<< endl;
					$$ = $1;
					$$->match=$1->match;
		            log_file << $$->match << endl; 
				}
				| simple_expression RELOP simple_expression
				{
					log_file << "Line " << line_no << " : rel_expression : simple_expression RELOP simple_expression\n"<< endl;
					SymbolInfo* temp = new SymbolInfo("INT");
					$$ = temp;	
					$$->match=$1->match+$2->Name+$3->match;
		            log_file << $$->match << endl; 
				}	
				;

				
simple_expression 	: term
					{
						log_file << "Line " << line_no << " : simple_expression : term\n"<< endl;
						$$ = $1;
						$$->match=$1->match;
		                log_file << $$->match << endl; 
					} 
		 			| simple_expression ADDOP term
					{
						log_file << "Line " << line_no << " : simple_expression : simple_expression ADDOP term\n"<< endl;
						if($1->VarType=="FLOAT" || $3->VarType=="FLOAT"){
			                SymbolInfo* temp = new SymbolInfo("FLOAT");
					        $$ = temp;			        
			            }
			            else{
			                SymbolInfo* temp = new SymbolInfo("INT");
					        $$ = temp;
			            }
						$$->match=$1->match+$2->Name+$3->match;
		                log_file << $$->match << endl; 
					} 	
					;

					
term :	unary_expression
		{
			log_file << "Line " << line_no << " : term : unary_expression\n"<< endl;
			$$ = $1;
			$$->match=$1->match;
		    log_file << $$->match << endl; 
		}
     	|term MULOP unary_expression
		{
			string mulop = $2->Name;
			log_file << "Line " << line_no << " : term : term MULOP unary_expression\n"<< endl;

			if(mulop == "*")
			{
			    if($1->VarType=="FLOAT" || $3->VarType=="FLOAT"){
			        SymbolInfo* temp = new SymbolInfo("FLOAT");
					$$ = temp;			        
			    }
			    else{
			        SymbolInfo* temp = new SymbolInfo("INT");
					$$ = temp;
			    }
			   
			}
			else if(mulop == "/")
			{
			    if($1->VarType=="FLOAT" || $3->VarType=="FLOAT"){
			        SymbolInfo* temp = new SymbolInfo("FLOAT");
					$$ = temp;			        
			    }
			    else{
			        SymbolInfo* temp = new SymbolInfo("INT");
					$$ = temp;
			    }
			}
			else if(mulop == "%"){
				SymbolInfo* temp = new SymbolInfo("INT");
				temp->IDType="VAR";
				if($1->VarType == "FLOAT" || $3->VarType == "FLOAT"){
					error_file << "Error at line " << line_no <<" : Invalid operand for mod operator"<<endl << endl;
					errors++;
				}
				$$ = temp;
			}
			$$->match=$1->match+$2->Name+$3->match;
		    log_file << $$->match << endl; 
		}
     	;
unary_expression : ADDOP unary_expression 
         {
            log_file << "Line " << line_no << " unary_expression : ADDOP unary_expression :\n"<< endl;
		    $$ = $2;   
		    $$->match=$1->Name+$2->match;
		    log_file << $$->match << endl;  
        } 
		 | NOT unary_expression 
		 {
		    log_file << "Line " << line_no << " unary_expression :NOT unary_expression :\n"<< endl;
            SymbolInfo* temp = new SymbolInfo("INT");
			temp->IDType="VAR";
			$$=temp; 
			$$->match="!"+$2->match;
		    log_file << $$->match << endl;       		 
		 }
		 | factor 
		 {
		    log_file << "Line " << line_no << " unary_expression : factor:\n"<< endl;
		    $$ = $1;
			$$->match=$1->match;
		    log_file << $1->match << endl;
		 }
		 ;
	
factor	: variable 
     {
        log_file << "Line " << line_no << " factor	: variable :\n"<< endl;
        $$=$1;
        $$->match=$1->match;
		log_file << $$->match << endl;
     }
	| ID LPAREN argument_list RPAREN
	{
	    log_file << "Line " << line_no << " factor	: ID LPAREN argument_list RPAREN:\n"<< endl;
	    SymbolInfo *temp=new SymbolInfo();
		temp = table->lookUp($1->Name);
		if(temp == NULL){
			error_file << "Error at line " << line_no <<" : Function " <<$1->Name <<" doesn't exist"<<endl << endl;
			errors++;
		}
		else{
			if(temp->FuncRet == "VOID"){
				error_file << "Error at line " << line_no <<" : Function " <<$1->Name <<" returns void"<<endl << endl;
				errors++;
			} 
			else{ 
				SymbolInfo *temp2 = new SymbolInfo($1->FuncRet);
				$$ = temp2;
				}
			}
			
		$$->match=$1->Name + "(" + $3->match+")";
		log_file << $$->match << endl;;		
			
	}
	| LPAREN expression RPAREN
    {
        log_file << "Line " << line_no << ": factor	: LPAREN expression RPAREN :\n"<< endl;
        $$ = $2;
        $$->match="(" + $2->match+")";
		log_file << $$->match << endl;;	
    }
	| CONST_INT 
    {
        log_file << "Line " << line_no << ": factor	: CONST_INT:\n"<< endl;
        $1->setVarType("INT");			
        $1->IDType="VAR";
        $1->val=atoi(($1->Name).c_str());
        $$ = $1;
        $$->match=$1->Name;
		log_file << $1->Name << endl;;	
    }
	| CONST_FLOAT
    {    
         log_file << "Line " << line_no << ": factor	: CONST_FLOAT:\n"<< endl;
         $1->setVarType("FLOAT");
         $1->IDType="VAR";
         $$ = $1; 
         $$->match=$1->Name;
		 log_file << $1->Name << endl;;	     
	}
	| CONST_CHAR
    {
	    log_file << "Line " << line_no << ": factor : CONST_CHAR\n";
	    $$ = $1;
	    $$->match=$1->Name;
		log_file << $1->Name << endl;;	
    }
	| variable INCOP 
	{
	    log_file << "Line " << line_no << ": factor	: variable INCOP :\n"<< endl;
		$$ = $1;
		$$->match=$1->match+"++";
		log_file<<$$->match<<endl;	
			    
	}
	| variable DECOP
	{
		log_file << "Line " << line_no << " : factor : variable DECOP\n"<< endl;
		$$ = $1;
		$$->match=$1->match+"--";
		log_file<<$$->match<<endl;	    
	}
	;
	
argument_list : arguments
              {
                  log_file << "Line " << line_no << ": argument_list : arguments:\n"<< endl;
                  $$->match=$1->match;
	              log_file<<$$->match<<endl;
              }
			  |
              {
                  //empty argument
              }
  			  ;
	
arguments : arguments COMMA logic_expression
          {
              log_file << "Line " << line_no << ": arguments : arguments COMMA logic_expression :\n"<< endl;
              $$->match=$1->match+","+$3->match;
	          log_file<<$$->match<<endl;
          }
	      | logic_expression
	      {
	          log_file << "Line " << line_no << ":arguments :logic_expression :\n"<< endl;
	          $$->match=$1->match;
	          log_file<<$$->match<<endl;
	      }     
	      ;
 
%%

int main(int argc,char *argv[])
{
	if((yyin=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}
	log_file.open("log.txt");
	error_file.open("errors.txt");
	yyparse();	
	log_file << "Total Lines : " << line_no << endl << endl; 
	log_file << "Total Errors : " << errors << endl;
	error_file << "Total Errors : " << errors << endl;
	log_file.close();
	error_file.close();
	return 0;
}

