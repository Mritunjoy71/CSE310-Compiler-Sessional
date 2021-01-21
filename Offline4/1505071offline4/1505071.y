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
ofstream log_file, error_file,asm_file;
extern string pp;
SymbolInfo *stmts=new SymbolInfo();
int nullp=0;
int labelCount=0;
int tempCount=0;
int pTempCount = 0;
int maxTemp = 0;
vector<string> variables;
vector<string> arrays;
vector<int> arraySizes;
int println=0;
int function_argument_size=0;
string function_argument_for_use[100];
int function_argument_size_for_use=0;
string globalvariables[1000];
int globalvariablessize=0;
string global_variable_declaration="";
char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	if(maxTemp < tempCount) maxTemp = tempCount;
	strcat(t,b);
	return t;
}
char *newPTemp()
{
	char *pt= new char[4];
	strcpy(pt,"p");
	char b[3];
	sprintf(b,"%d", pTempCount);
	pTempCount++;
	strcat(pt,b);
	return pt;
}
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

%type <symVal>type_specifier expression logic_expression rel_expression simple_expression term unary_expression factor variable expression_statement statement compound_statement  declaration_list var_declaration statements func_declaration  func_definition parameter_list unit program arguments argument_list start

%nonassoc second_precedence
%nonassoc ELSE 
%error-verbose


%%
start : program {
		            log_file << "Line " << line_no << " : start : program\n"<< endl;
		            log_file<<pp<<endl;
		           // cout<<$1->code;
		            if(!errors){
		            $$=$1;
		            if(println){
			            $$->code+="\n\nDECIMAL_OUT PROC \n\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\tor ax,ax\n \tjge enddif\n\tpush ax\n\tmov dl,'-'\n\tmov ah,2\n\tint 21h\n\tpop ax\n\tneg ax\nenddif:\n\txor cx,cx\n\tmov bx,10d\nrepeat:\n\txor dx,dx\n\tdiv bx\n\t push dx\n\tinc cx\n\tor ax,ax\n\tjne repeat\n\tmov ah,2\nprint_loop:\n\tpop dx\n\tor dl,30h\n\tint 21h\n\tloop print_loop\n\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\n\nDECIMAL_OUT ENDP\n";
			            }
			        
			        asm_file << ".model small\n.stack 100h\n\n.data\n" ;
			        asm_file<<global_variable_declaration;
			        for(int i=0;i<maxTemp;i++)
			            asm_file<<"t"<<i<<" DW 0"<<endl;
			            
                    for(int i=0;i<pTempCount;i++)
			            asm_file<<"p"<<i<<" DW 0"<<endl;
			        asm_file  << "\n.code \n"; 
			        asm_file  << $$->code;
			        asm_file<<"end main\n";
			        //cout<<$1->code;
		            
		        }
		    }    
    ; 

program : program unit {
			                log_file << "Line " << line_no << " : program : program unit\n"<< endl;
			                $$ = $1;
		                    $$->code =$1->code+ $2->code;
			                $$->match= $1->match+"\n" + $2->match;
				            log_file<<$$->match<<endl;
				           // cout<<$1->code;
			           } 
	| unit  {	
			    log_file << "Line " << line_no << " : program : unit\n"<< endl;
			    $$=$1;
			    $$->match= $1->match;
				log_file<<$$->match<<endl;
				//cout<<$$->code;
			    
	        }
	;
	
unit : var_declaration {
			                log_file << "Line " << line_no << " : unit : var_declaration\n"<< endl;
			                $$=$1;
			                $$->match= $1->match;
				            log_file<<$$->match<<endl;
	                	}
     | func_declaration {
			                log_file << "Line " << line_no << " : unit : func_declaration\n"<< endl;
			                $$=$1;
			                $$->match= $1->match;
				            log_file<<$$->match<<endl;
                    	}
     | func_definition {
			                log_file << "Line " << line_no << " : unit : func_definition\n"<< endl;
			                $$=$1;
			                $$->match= $1->match ;
				            log_file<<$$->match<<endl;
				           // cout<<$$->code;
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
				
				SymbolInfo * func = new SymbolInfo();				
				$$ = func;
				$$->code += $2->Name + " proc \n\n";
				$$->code += $6->code;
				if(parameters.size()!=0){
					$$->code+="\tpop bp\n";
				}
				if($2->Name!="main"){
					$$->code+="\tret ";
				}
		
				
				$$->code+="\n";
				if($2->Name=="main"){
					$$->code+="\tmov ah,4ch\n\tint 21h\n";
				}
				$$->code += "\n" + $2->Name + " endp\n\n";
				
				parameters.clear();
				IDparameters = 0;
				//return_label = "";
				$$->match= $1->match +$2->Name+" (" +$4->match+") " + "\n" +$6->match;
				log_file<<$$->match<<endl;
				//cout<<$$->code;
				
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
				    
				    SymbolInfo * func = new SymbolInfo();				
				    $$ = func;
				    $$->code += $2->Name + " PROC \n\n";
				    $$->code += $5->code;
				    if(parameters.size()!=0){
					    $$->code+="\tpop bp\n";
				    }
				    if($2->Name!="main"){
					    $$->code+="\tret ";
				    }
		
				    int p=parameters.size()*2;
				    if(p){
					    string Result;       

					    ostringstream convert;  
	
					    convert << p;    

					    Result = convert.str(); 
					    $$->code+=Result+"\n";
				    }
				    $$->code+="\n";
				    if($2->Name=="main"){
					    $$->code+="\tmov ah,4ch\n\tint 21h\n";
				    }
				    $$->code += "\n" + $2->Name + " ENDP\n\n";
				
				    parameters.clear();
				    IDparameters = 0;
				  //  return_label = "";
				    
				    $$->match= $1->match +$2->Name+" ("+") " + "\n" +$5->match;
				    log_file<<$$->match<<endl;
		            //cout<<$$->code;
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
					
					globalvariables[globalvariablessize]=$4->Name+to_string(table->count+1);
	                globalvariablessize++;
	                global_variable_declaration+=$4->Name+to_string(table->count+1)+" DW 0\n";
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
					
					globalvariables[globalvariablessize]=$2->Name+to_string(table->count+1);
	                globalvariablessize++;
	                global_variable_declaration+=$2->Name+to_string(table->count+1)+" DW 0\n";
					
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
							$$=$3;
							$$->match= "{\n" +stmts->match + "}" ;
						    log_file<<$$->match<<endl;
						     //cout<<$$->code;
						}
 		    			| LCURL RCURL
 		    			{
 		    			    log_file << "Line " << line_no << " : compound_statement : LCURL RCURL\n"<< endl;
 		    			    table->enterScope(); 
							for(int i = 0; i<params.size(); i++) table->Insert(params[i]);
							
							table->printAll(log_file);
							
							params.clear();
							
							table->exitScope();
							SymbolInfo* s=new SymbolInfo();
	                        $$=s;
	                        $$->code="";
							
                            $$->match="{ }";
						    log_file<<$$->match<<endl;		    			
 		    			}
 		    			;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
                {
                    log_file << "Line " << line_no << " : var_declaration : type_specifier declaration_list SEMICOLON\n"<< endl;
                    $$=$2;
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
	                    globalvariables[globalvariablessize]=$3->Name+to_string(table->count);
	                    globalvariablessize++;
	                    global_variable_declaration+=$3->Name+to_string(table->count)+" DW 0\n";
	                    SymbolInfo* s=new SymbolInfo();
	                    $$=s;
	                    $$->code="";
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
						global_variable_declaration+=$3->Name+to_string(table->count)+" DW "+to_string(2*atoi(($5->Name).c_str()))+" dup(0)\n";
		                globalvariables[globalvariablessize]=$3->Name+to_string(table->count);
		                globalvariablessize++;
						
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
	                    globalvariables[globalvariablessize]=$1->Name;
	                    globalvariablessize++;
	                    global_variable_declaration+=$1->Name+to_string(table->count)+" DW 0\n";
	                    SymbolInfo* s=new SymbolInfo();
	                    $$=s;
	                    $$->code="";
						
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
						SymbolInfo* s=new SymbolInfo();
	                    $$=s;
	                    $$->code="";
		                global_variable_declaration+=$1->Name+to_string(table->count)+" DW "+to_string(2*atoi(($3->Name).c_str()))+" dup(0)\n";
		                globalvariables[globalvariablessize]=$1->Name+to_string(table->count);
		                globalvariablessize++;
		               // }
						
						$$->match=$1->Name+"["+$3->Name+"]";
						log_file<<$$->match<<endl;
					}						
					;
 		  
statements : statement
       {
           log_file << "Line " << line_no << " : statements : statement\n"<< endl;
           $$=$1;
           $$->match=$1->match+"\n";
		   log_file<<$$->match<<endl;   
		   stmts->match=$$->match;
       }
	   | statements statement
	   {    
	       log_file << "Line " << line_no << " : statements : statements statement\n"<< endl;
	       $$=$1;
		   $$->code += $2->code;
           $$->match=$1->match+"\n"+$2->match+"\n";
		   log_file<<$$->match<<endl;   
		   stmts->match=$$->match;
		   //cout<<$$->code;
	   }
	   ;
	   
statement : var_declaration
      {
          log_file << "Line " << line_no << " : statement : var_declaration\n"<< endl;
          $$=$1;
          $$->match=$1->match;
		  log_file<<$$->match<<endl;       
     }
	  | expression_statement
	  {
	      log_file << "Line " << line_no << " : statement : expression_statement\n"<< endl;
	      $$=$1;
	      $$->match=$1->match;
	      log_file<<$$->match<<endl;	     
	  	  }
	  | compound_statement
	  {
	      log_file << "Line " << line_no << " : statement : compound_statement\n"<< endl;
	      $$=$1;
	      $$->match=$1->match;
		  log_file<<$$->match<<endl;
	  }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	  {
	        log_file << "Line " << line_no << " : statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<< endl;
	      
            $$ = $3;
            char *label1 = newLabel();
            char *label2 = newLabel();
            $$->code += string(label1) + ":\n";
            $$->code+=$4->code;
            $$->code+="\tmov ax , "+$4->Name+"\n";
            $$->code+="\tcmp ax , 0\n";
            $$->code+="\tje "+string(label2)+"\n";
            $$->code+=$7->code;
            $$->code+=$5->code;
            $$->code+="\tjmp "+string(label1)+"\n";
            $$->code+=string(label2)+":\n";
	      
	        $$->match="for(" + $3->match+ $4->match+$5->match+" )"+$7->match;
		    log_file<<$$->match<<endl;
	      
	      
	  }
	  | IF LPAREN expression RPAREN statement %prec second_precedence
	  { 
            log_file << "Line " << line_no << " : statement : IF LPAREN expression RPAREN statement\n"<< endl;

            $$=$3;
            char *label=newLabel();
            $$->code+="\tmov ax, "+$3->Name+"\n";
            $$->code+="\tcmp ax, 0\n";
            $$->code+="\tje "+string(label)+"\n";
            $$->code+=$5->code;
            $$->code+=string(label)+":\n";

            $$->match="if("+$3->match+" )"+$5->match;
            log_file<<$$->match<<endl;
	  } 
	  | IF LPAREN expression RPAREN statement ELSE statement 
	  {
	        log_file << "Line " << line_no << " : statement : IF LPAREN expression RPAREN statement ELSE statement\n"<< endl;
	          
	        $$=$3;
		    //similar to if part
		    char *elselabel=newLabel();
		    char *exitlabel=newLabel();
		    $$->code+="\tmov ax,"+$3->Name+"\n";
		    $$->code+="\tcmp ax,0\n";
		    $$->code+="\tje "+string(elselabel)+"\n";
		    $$->code+=$5->code;
		    $$->code+="\tjmp "+string(exitlabel)+"\n";
		    $$->code+=string(elselabel)+":\n";
		    $$->code+=$7->code;
		    $$->code+=string(exitlabel)+":\n";
	          
	        $$->match="if("+$3->match+" )"+$5->match+"else"+$7->match;
	        log_file<<$$->match<<endl;
	   }
	  | WHILE LPAREN expression RPAREN statement
	  { 
	        log_file << "Line " << line_no << " : statement : WHILE LPAREN expression RPAREN statement\n"<< endl;
	          
	        $$ = new SymbolInfo();
		    char * label = newLabel();
		    char * exit = newLabel();
		    $$->code = string(label) + ":\n"; 
		    $$->code+=$3->code;
		    $$->code+="\tmov ax , "+$3->Name+"\n";
		    $$->code+="\tcmp ax , 0\n";
		    $$->code+="\tje "+string(exit)+"\n";
		    $$->code+=$5->code;
		    $$->code+="\tjmp "+string(label)+"\n";
		    $$->code+=string(exit)+":\n";
	          
	        $$->match="while("+$3->match+" )"+$5->match;
	        log_file<<$$->match<<endl;
	  }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  { 
            log_file << "Line " << line_no << " : statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<< endl;
            println=1;
            $$=new SymbolInfo("println","nonterminal");
            $$->code += "\tmov ax, " + $3->Name +"\n";
            $$->code += "\tcall DECIMAL_OUT\n";
            $$->match="println("+$3->match+" )"+";";
            log_file<<$$->match<<endl;
	  }		 		
	  | RETURN expression SEMICOLON
	  {
            log_file << "Line " << line_no << " : statement : RETURN expression SEMICOLON\n"<< endl;
            $$=$2;
            $$->code+="\tmov ax,"+$2->Name+"\n";
            $$->match="return "+$2->match + ";";
            log_file<<$$->match<<endl;
	  }		 			
	  ;
	  
	  
expression_statement 	: SEMICOLON
                        {
                            log_file << "Line " << line_no << " : expression_statement : SEMICOLON\n"<< endl;
                            $$=new SymbolInfo(";","SEMICOLON");
							$$->code="";
							tempCount = 0;
							
                            $$->match=";";
		                    log_file << $$->match << endl;
		                }			
						| expression SEMICOLON 
						{
						    log_file << "Line " << line_no << " : expression_statement : expression SEMICOLON\n"<< endl;
						    $$=$1;
							tempCount = 0;
						    
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
					$$= new SymbolInfo($1);
					$$->code="";
					$$->Name=$$->Name+to_string(table->count);
					variables.push_back($$->Name);
					$$->Type="notarray";
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
				    $$= new SymbolInfo($1);
					$$->Type="array";
					$$->Name=$1->Name+to_string(table->count);
					arrays.push_back($$->Name);
					arraySizes.push_back($1->AraSize);
					$$->code=$3->code ;
					$$->code += "\tmov bx, " +$3->Name +"\n";
					$$->code += "\tadd bx, bx\n";			
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
				$$->code=$3->code+$1->code;
				$$->code+="\tmov ax, "+$3->Name+"\n";
				if($$->Type=="notarray"){ 
					$$->code+= "\tmov "+$1->Name+", ax\n";
				}				
				else{
					$$->code+= "\tmov  "+$1->Name+"[bx], ax\n";
				}
				//cout<<$$->code;
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
						
					    $$->code=$1->code+$3->code;
					    char * label1 = newLabel();
					    char * label2 = newLabel();
					    char * t = newPTemp();
					    if($2->Name=="&&"){
						    /* 
						    Check whether both operands value is 1. If both are one set value of a temporary variable to 1
						    otherwise 0
						    */
						    $$->code += "\tmov ax , " + $1->Name +"\n";
						    $$->code += "\tcmp ax , 0\n";
				     		$$->code += "\tje " + string(label1) +"\n";
						    $$->code += "\tmov ax , " + $3->Name +"\n";
						    $$->code += "\tcmp ax , 0\n";
						    $$->code += "\tje " + string(label1) +"\n";
						    $$->code += "\tmov " + string(t) + " , 1\n";
						    $$->code += "\tjmp " + string(label2) + "\n";
						    $$->code += string(label1) + ":\n" ;
						    $$->code += "\tmov " + string(t) + ", 0\n";
						    $$->code += string(label2) + ":\n";
						    $$->Name=t;						
					    }
					    else if($2->Name=="||"){
						    $$->code += "\tmov ax , " + $1->Name +"\n";
						    $$->code += "\tcmp ax , 0\n";
				     		$$->code += "\tjne " + string(label1) +"\n";
						    $$->code += "\tmov ax , " + $3->Name +"\n";
						    $$->code += "\tcmp ax , 0\n";
						    $$->code += "\tjne " + string(label1) +"\n";
						    $$->code += "\tmov " + string(t) + " , 0\n";
						    $$->code += "\tjmp " + string(label2) + "\n";
						    $$->code += string(label1) + ":\n" ;
						    $$->code += "\tmov " + string(t) + ", 1\n";
						    $$->code += string(label2) + ":\n";
						    $$->Name=t;						
			    	    }
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
					
			        $$->code=$1->code+$3->code;
			        $$->code+="\tmov ax, " + $1->Name+"\n";
			        $$->code+="\tcmp ax, " + $3->Name+"\n";
			        char *t=newPTemp();
			        char *label1=newLabel();
			        char *label2=newLabel();
			        if($2->Name=="<"){
				        $$->code+="\tjl " + string(label1)+"\n";
			        }
			        else if($2->Name=="<="){
				        $$->code+="\tjle " + string(label1)+"\n";
			        }
			        else if($2->Name==">"){
				        $$->code+="\tjg " + string(label1)+"\n";
			        }
			        else if($2->Name==">="){
				        $$->code+="\tjge " + string(label1)+"\n";
			        }
			        else if($2->Name=="=="){
				        $$->code+="\tje " + string(label1)+"\n";
			        }
			        else if($2->Name=="!="){
				        $$->code+="\tjne " + string(label1)+"\n";
			        }
			
			        $$->code+="\tmov "+string(t) +", 0\n";
			        $$->code+="\tjmp "+string(label2) +"\n";
			        $$->code+=string(label1)+":\n";
			        $$->code+= "\tmov "+string(t)+", 1\n";
			        $$->code+=string(label2)+":\n";
			        $$->Name=t;
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
			            $$->code=$1->code+$3->code; 
					    if($2->Name=="+"){
					        char* temp = newTemp();
					        $$->code += "\tmov ax, " + $1->Name + "\n";
					        $$->code += "\tadd ax, " + $3->Name + "\n";
					        $$->code += "\tmov " + string(temp) +" , ax\n";
					        $$->Name=string(temp);
					        //cout<<$$->code;
				        }
				        else if($2->Name == "-"){
					        char* temp = newTemp();
					        $$->code += "\tmov ax, " + $1->Name + "\n";
					        $$->code += "\tsub ax, " + $3->Name + "\n";
					        $$->code += "\tmov " + string(temp) +" , ax\n";
					        $$->Name=string(temp);
					         //cout<<$$->code;
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
			
			char *t=newTemp();

			if(mulop == "*")
			{
			    if($1->VarType=="FLOAT" || $3->VarType=="FLOAT"){
			        SymbolInfo* temp = new SymbolInfo("FLOAT");
					$$ = temp;			        
			    }
			    else{
			        SymbolInfo* temp = new SymbolInfo("INT");
					$$ = temp;
					$$->code =$1->code + $3->code;
			        $$->code += "\tmov ax, "+ $1->Name+"\n";
			        $$->code += "\tmov bx, "+ $3->Name +"\n";
			        $$->code += "\tmul bx\n";
				    $$->code += "\tmov "+ string(t) + ", ax\n";
				    //cout<<$$->code;
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
					$$->code =$1->code + $3->code;
			        $$->code += "\tmov ax, "+ $1->Name+"\n";
			        $$->code += "\tmov bx, "+ $3->Name +"\n";
			        $$->code += "\txor dx , dx\n";
				    $$->code += "\tdiv bx\n";
				    $$->code += "\tmov "+ string(t) + ", ax\n";
				   // cout<<$$->code;
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
				
				$$->code =$1->code + $3->code;
			    $$->code += "\tmov ax, "+ $1->Name+"\n";
			    $$->code += "\tmov bx, "+ $3->Name +"\n";
			    $$->code += "\txor dx , dx\n";
				$$->code += "\tdiv bx\n";
				$$->code += "\tmov " + string(t) + " , dx\n";
				//cout<<$$->code;
			}
			$$->Name=t;
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
		    
		    if($1->Name == "-"){
		        $$->code += "\tmov ax, " + $2->Name + "\n";
				$$->code += "\tneg ax\n";
				$$->code += "\tmov " + $2->Name + " , ax\n";		
						
		       }
        } 
		 | NOT unary_expression 
		 {
		    log_file << "Line " << line_no << " unary_expression :NOT unary_expression :\n"<< endl;
            SymbolInfo* temp = new SymbolInfo("INT");
			temp->IDType="VAR";
			$$=temp; 
			$$->match="!"+$2->match;
		    log_file << $$->match << endl;    
		    
			$$->code="\tmov ax, " + $2->Name + "\n";
			$$->code+="\tnot ax\n";
			$$->code+="\tmov "+ $2->Name+", ax"; 		 
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
		
		if($$->Type=="notarray"){
		    
				
			}
		else{
			char *temp= newTemp();
			$$->code+="\tmov ax, " + $1->Name + "[bx]\n";
			$$->code+= "\tmov " + string(temp) + ", ax\n";
			$$->Name=string(temp);
			//cout<<$$->code; 
			}
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
				//SymbolInfo *temp2 = new SymbolInfo($1->FuncRet);
				$1->VarType=$1->FuncRet;
				$$ =$1;
				}
			}	
		$$->code="";
		$$->code+=$3->code;
		for(int i=0;i<function_argument_size_for_use;i++){
		$$->code+="\tmov ax,"+function_argument_for_use[i]+"\n";
		$$->code+="\tpush ax\n";
		}
		$$->code+="\tcall "+$1->Name+"\n";
		$$->code+="\tpop ax\n";
		char *Temp= newTemp();
		$$->code+="\tmov "+string(Temp)+",ax\n";
		$$->Name=string(Temp);
		function_argument_size_for_use=0;
		
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
		// perform incop depending on whether the varaible is an array or not
		if($1->Type=="notarray"){
		char* TEMP=newTemp();
		$$->code+="\tmov ax,"+$1->Name+"\n";
		$$->code+="\tmov "+string(TEMP)+",ax\n";
		$$->code+="\tinc ax\n";
		$$->code+="\tmov "+$1->Name+", ax\n";
		$$->Name=string(TEMP);
		
		}else{
		char* TEMP=newTemp();
		$$->code+="\tmov ax,"+$1->Name+"[bx]\n";
		$$->code+="\tmov "+string(TEMP)+",ax\n";
		$$->code+="\tinc ax\n";
		$$->code+="\tmov "+$1->Name+"[bx], ax\n";
		$$->Name=string(TEMP);
		}
		//cout<<$$->code; 		
		
		$$->match=$1->match+"++";
		log_file<<$$->match<<endl;		    
	}
	
	| variable DECOP
	{
		log_file << "Line " << line_no << " : factor : variable DECOP\n"<< endl;
		$$ = $1;
		if($1->Type=="notarray"){
		char* TEMP=newTemp();
		$$->code+="\tmov ax,"+$1->Name+"\n";
		$$->code+="\tmov "+string(TEMP)+",ax\n";
		$$->code+="\tdec ax\n";
		$$->code+="\tmov "+$1->Name+" ,ax\n";
		$$->Name=string(TEMP);
		
		}else{
		char* TEMP=newTemp();
		$$->code+="\tmov ax,"+$1->Name+"[bx]\n";
		$$->code+="\tmov "+string(TEMP)+",ax\n";
		$$->code+="\tdec ax\n";
		$$->code+="\tmov "+$1->Name+"[bx], ax\n";
		$$->Name=string(TEMP);
		}
		
		$$->match=$1->match+"--";
		log_file<<$$->match<<endl;	  
		//cout<<$$->code; 		
	}
	;
	
argument_list : arguments
              {
                  log_file << "Line " << line_no << ": argument_list : arguments:\n"<< endl;
                  $$=$1;
                  $$->match=$1->match;
	              log_file<<$$->match<<endl;
              }
			  |
              {
                  SymbolInfo* temp=new SymbolInfo();
                  $$=temp;
                  $$->code="";
                  function_argument_size_for_use=0;
              }
  			  ;
	
arguments : arguments COMMA logic_expression
          {
              log_file << "Line " << line_no << ": arguments : arguments COMMA logic_expression :\n"<< endl;
              SymbolInfo* temp=new SymbolInfo();
	          temp->code=$1->code+$3->code;
	          function_argument_for_use[function_argument_size_for_use]=$3->Name;
		      function_argument_size_for_use++;
		      $$=temp;
              
              $$->match=$1->match+","+$3->match;
	          log_file<<$$->match<<endl;
          }
	      | logic_expression
	      {
	          log_file << "Line " << line_no << ":arguments :logic_expression :\n"<< endl;
	          $$=$1;
	          function_argument_for_use[function_argument_size_for_use]=$1->Name;
		      function_argument_size_for_use++;
		      
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
	asm_file.open("asmcode.asm");
	yyparse();	
	log_file << "Total Lines : " << line_no << endl << endl; 
	log_file << "Total Errors : " << errors << endl;
	error_file << "Total Errors : " << errors << endl;
	log_file.close();
	error_file.close();
	asm_file.close();
	return 0;
}

