%{
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include <string>
#include "1405038.h"
#include "mytype.h"
#include <sstream>
using namespace std;
int yyparse(void);
int current_function_parameter_size=0;
char* current_function_return_label;
int yylex(void);
myytype* for_function;
string globalvariables[1000];
int globalvariablessize=0;
extern int errors;
extern FILE *yyin;
extern int yylineno;
maain main_scopetable;
string global_variable_declaration="";
int function_flag=0;//1 hoile kono notun scope e jabe na function_scopetable
int array_index;
int function_scope=0;//0 hoile eta function na kono
ofstream lout,err,sym,tt;
string declare_type;
string function_argument[100];
int function_argument_size=0;
string function_argument_for_use[100];
int function_argument_size_for_use=0;
int labelCount=0;
int tempCount=0;
int match(string s){
int p=1;//1 hoile insert kora jabe
for(int i=0;i<globalvariablessize;i++){
	if(globalvariables[i]==s){
	p=0;//insert kora jabe na
	return 0;
	}
}
return p;
}
void yyerror(string s)
{
	lout<<"LINENO"<<yylineno<<s<<endl;errors++;
	err<<"LINENO"<<yylineno<<s<<endl;
}



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
	strcat(t,b);
	return t;
}

%}
%union { 
symbolinfo* symval;
char* strval;
myytype* Mytype;
}
%token IF ELSE FOR WHILE  DO INT FLOAT VOID SWITCH DEFAULT BREAK CHAR DOUBLE RETURN CASE CONTINUE 
INCOP DECOP  ASSIGNOP NOT LPAREN RPAREN LCURL
RCURL LTHIRD RTHIRD COMMA SEMICOLON  PRINTLN
%error-verbose
%token  <symval>ADDOP

%token <symval>STRING
%token <symval>RELOP
%token <symval>LOGICOP 
%token  <symval>CONST_INT 

%nonassoc else_priority
%nonassoc ELSE
%token <symval>ID 
%token<symval>CONST_CHAR
%token <symval>CONST_FLOAT

//%start start
%type <Mytype>argument_list

%type <Mytype>arguments
%type <Mytype>statement
%type <Mytype>parameter_list
%type <Mytype>parameters
%type <Mytype>statements
%type <Mytype>declaration_list 
%type <Mytype>var_declaration
%type <Mytype>func_declaration
%type <Mytype>func_definition
%type <Mytype>start
%type <Mytype> expression_statement
%type <Mytype>compound_statement
%type <Mytype>program
%type <Mytype>unit
%type <Mytype>type_specifier
%type <symval>variable
%type <Mytype>logic_expression
%type <Mytype>rel_expression
%type <Mytype>simple_expression
%type <Mytype>expression
%type <Mytype>term
%type <Mytype>unary_expression
%type <Mytype> factor
%left ASSIGNOP 
%left NOT
%left ADDOP

%left RELOP
%left LOGICOP
%token <symval> MULOP
%left MULOP
%right INCOP
%right DECOP

%%

start : program
	{
	yylineno--;
	lout<<"Line No:"<<yylineno<<"start : program\n";
	main_scopetable.printall(lout);
	myytype* temp=new myytype();
	$$=temp;
	$$->code="";
	$$->code+=".model small\n .stack 100h\n .data\n";
	for(int i=0;i<tempCount-1;i++){
	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << i;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str(); 
	$$->code+="t"+Result+" DW 0\n";
	}
	$$->code+=global_variable_declaration;
	$$->code+=$1->code;
	$$->code+="end main\n";
	tt<<$$->code;	
	}
	;

program : program unit 
	{
	$$=$1;
	$$->code+=$2->code;
	lout<<"Line No:"<<yylineno<<"program : program unit \n";
		
	} 
	| 
	unit
	{$$=$1;
	lout<<"Line No:"<<yylineno<<"program :unit\n";
		
	}
	;
	
unit : var_declaration  
	{$$=$1;
	lout<<"Line No:"<<yylineno<<"unit : var_declaration  \n";
	}
     	| 
     	func_declaration 
     	{$$=$1;
	lout<<"Line No:"<<yylineno<<"unit :func_declaration  \n";
     	}
     	| 
     	func_definition  
     	{$$=$1;
	lout<<"Line No:"<<yylineno<<"unit :func_definition\n";
     	}
     	;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON 
			{
		
			}
		 	;
func_definition : type_specifier ID LPAREN parameter_list RPAREN {
		current_function_return_label=newLabel();
		int result;//1 hoile mile nai insert kora jabe
		myytype* temp=new myytype();
		for_function=temp;
		for_function->code="";
		for_function->code+=$2->getname()+" proc near\n\npush bp\n mov bp,sp\n";
		current_function_parameter_size=function_argument_size;
		int j=4;
		for(int i=function_argument_size-1;i>=0;i--){
			result=match(function_argument[i]);
			if(result==0){}
			else{
			global_variable_declaration+=function_argument[i]+" dw 0\n";
			globalvariables[globalvariablessize]=function_argument[i];
			globalvariablessize++;
			}
			//$$->code+="pop ax\n";
			string Result;          // string which will contain the result

			ostringstream convert;   // stream used for the conversion

			convert << j;      // insert the textual representation of 'Number' in the characters in the stream

			Result = convert.str(); 
			for_function->code+="mov ax,[bp+"+Result+"]\n";
			for_function->code+="mov "+function_argument[i]+",ax\n";
			j=j+2;
		}
		
//tt<<$<Mytype>$->code;
		
}compound_statement{$$=for_function;
		$$->code+=$7->code;
		$$->code+=string(current_function_return_label)+":\n";
		$$->code+="pop bp\n";
		$$->code+="ret ";
		int p=current_function_parameter_size*2;
		if(p){
		string Result;          // string which will contain the result

			ostringstream convert;   // stream used for the conversion

			convert << p;      // insert the textual representation of 'Number' in the characters in the stream

			Result = convert.str(); 
			$$->code+=Result+"\n";
		}
		$$->code+="\n";
		$$->code+=$2->getname()+"endp\n";
		function_argument_size=0;current_function_parameter_size=0;for_function=NULL;current_function_return_label=NULL;}
			
		;
 parameter_list : parameters {}
                    |{}
                    ;
 		 
parameters  : parameters  COMMA type_specifier ID //sesh define function declare parameters complete
		{function_argument[function_argument_size]=$4->getname();function_argument_size++;
		
		
		}
		



		| parameters COMMA type_specifier 
		{
		
		}

	 
 		| type_specifier ID
		{
		function_argument_size=0;
		function_argument[function_argument_size]=$2->getname();function_argument_size++;
		
		}
		


 		| type_specifier
		{
		}


 		
 		;
 		
compound_statement : LCURL statements RCURL //exit enter scope
			{$$=$2;
			
			}


 		    | LCURL RCURL
			{myytype *temp=new myytype();
			temp->code="";
			$$=temp;
			
			}
 		    ;


 		    
var_declaration : type_specifier declaration_list SEMICOLON 
			{$$=$2;
			//declare_type=$1->type;
			lout<<"Line No:"<<yylineno<<"var_declaration : type_specifier declaration_list SEMICOLON\n";
			}
 		 ;
 		 
type_specifier	: INT 
		{
		myytype* temp=new myytype();
		temp->type = "CONST_INT";
		declare_type="CONST_INT";
		$$=temp;
		lout<<"Line No:"<<yylineno<<"type_specifier: INT\n";}


 		| FLOAT
		{myytype* temp=new myytype();
		temp->type = "CONST_FLOAT";
		declare_type="CONST_FLOAT";
		$$=temp;
		lout<<"Line No:"<<yylineno<<"type_specifier| FLOAT\n";}


 		| VOID
		{myytype* temp=new myytype();
		temp->type = "VOID";
		declare_type="VOID";
		$$=temp;
		lout<<"Line No:"<<yylineno<<"type_specifier| VOID\n";}
		
 		;
 		
declaration_list : declaration_list COMMA ID//ide declare complete
		{int result;
		result=match($3->getname());
		if(result==0){}
		else{
		globalvariables[globalvariablessize]=$3->getname();globalvariablessize++;
		global_variable_declaration+=$3->getname()+" DW 0\n";
		}
		myytype* temp=new myytype();temp->code="";$$=temp;}

 		  | ID
		{int result;//insert kora jabe
		result=match($1->getname());
		if(result==0){}
		else{
		global_variable_declaration+=$1->getname()+" DW 0\n";
		globalvariables[globalvariablessize]=$1->getname();globalvariablessize++;
		}
		myytype* temp=new myytype();temp->code="";$$=temp;
		}


 		  | ID LTHIRD CONST_INT RTHIRD //int a[2]//declare array complete
		{myytype* temp=new myytype();temp->code="";$$=temp;
		int result;
		result=match($1->getname());
		if(result==0){}
		else{
		global_variable_declaration+=$1->symbol+" DW "+$3->getname()+"dup (0)\n";
		globalvariables[globalvariablessize]=$1->getname();globalvariablessize++;
		}
		}
 		  ;
 		  


statements : statement
		{$$=$1;
		}
	   | statements statement
		{$$=$1;
		$$->code += $2->code;
		delete $2;
		}
	   ;
	   
statement : var_declaration
		{$$=$1;lout<<"Line No:"<<yylineno<<"statement: var_declaration \n";}
	  | expression_statement
		{$$=$1;lout<<"Line No:"<<yylineno<<"statement | expression_statement \n";}
	  | compound_statement
		{$$=$1;lout<<"Line No:"<<yylineno<<"statement | compound_statement \n";}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	{	$$=$3;
		char *label1=newLabel();
		char *label2=newLabel();
		$$->code+=string(label1)+":\n";
		$$->code+=$4->code;
		$$->code+="mov ax, "+$4->symbol+"\n";
		$$->code+="cmp ax, 0\n";
		$$->code+="je "+string(label2)+"\n";
		$$->code+=$7->code;
		$$->code+=$5->code;
		$$->code+="jmp "+string(label1)+"\n";
		$$->code+=string(label2)+":\n";
		lout<<"Line No:"<<yylineno<<"statement | FOR LPAREN expression_statement expression_statement expression RPAREN statement\n";}
	  | IF LPAREN expression RPAREN statement %prec else_priority
		{$$=$3;		
		char *label=newLabel();
		$$->code+="mov ax, "+$3->symbol+"\n";
		$$->code+="cmp ax, 0\n";
		$$->code+="je "+string(label)+"\n";
		$$->code+=$5->code;
		$$->code+=string(label)+":\n";
		cout<<"Line No:"<<yylineno<<"statement | IF LPAREN expression RPAREN statement \n";}
	  | IF LPAREN expression RPAREN statement ELSE statement
		{$$=$3;		
		char *elselabel=newLabel();
		char *exitlabel=newLabel();
		$$->code+="mov ax, "+$3->symbol+"\n";
		$$->code+="cmp ax, 0\n";
		$$->code+="je "+string(elselabel)+"\n";
		$$->code+=$5->code;
		$$->code+="jmp "+string(exitlabel)+"\n";
		$$->code+=string(elselabel)+":\n";
		$$->code+=$7->code;
		$$->code+=string(exitlabel)+":\n";
		lout<<"Line No:"<<yylineno<<"statement  | IF LPAREN expression RPAREN statement ELSE statement\n";}
	  | WHILE LPAREN expression RPAREN statement
		{myytype* p=new myytype();
		$$=p;
		char* label=newLabel();
		char* exitlabel=newLabel();
		$$->code=string(label)+":\n";
		$$->code+=$3->code;
		$$->code+="mov ax,"+$3->symbol+"\n";
		$$->code+="cmp ax, 0\n";
		$$->code+="je "+string(exitlabel)+"\n";
		$$->code+=$5->code;
		$$->code+="jmp "+string(label)+"\n";
		$$->code+=string(exitlabel)+":\n";
		lout<<"Line No:"<<yylineno<<"statement | WHILE LPAREN expression RPAREN statement\n";}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
		{char* temp=newTemp();
		myytype* r=new myytype();
		r->code="mov dx,"+$3->getname()+"\n";
		r->code+="mov ah,2\n";
		r->code+="int 21h\n";
		$$=r;

lout<<"Line No:"<<yylineno<<"statement | PRINTLN LPAREN ID RPAREN SEMICOLON\n";}
	  | RETURN expression SEMICOLON
		{$$=$2;
		
		$$->code+="mov ax,"+$2->symbol+"\n";
		//$$->code+="push ax\n";
		$$->code+="jmp   "+string(current_function_return_label)+"\n";
		tt<<"Line No:"<<yylineno<<"statement  | RETURN expression SEMICOLON\n";}
	  ;
	  
expression_statement 	: SEMICOLON	
		{myytype* p=new myytype();
		p->code="";
		$$=p;
		}		
			| expression SEMICOLON 
		{$$=$1;}
			;
	  
variable : ID 		//usepart
		{
		
		$$=$1;
		$$->symbol=$1->getname();
		$$->code="";
		
		}
		
		
		
	 | ID LTHIRD expression RTHIRD //usepart
		{
		symbolinfo* temp=new symbolinfo();
		temp->symbol=$1->getname();
		$$=temp;
		$$->code=$3->code+"mov bx, " +$3->symbol +"\nadd bx, bx\n";
		
		
		
		}
		
	 ;
	 
 expression : logic_expression	//
		{$$=$1;
		lout<<"Line No:"<<yylineno<<" expression : logic_expression	\n";}
	   | variable ASSIGNOP logic_expression //for look upin symbol table for variable then update match for value type
		{myytype* p=new myytype();
		$$=p;
				$$->code=$1->code+$3->code;
				$$->code+="mov ax, "+$3->symbol+"\n";
				if($1->id_type!="ARRAY"){ 
					$$->code+= "mov "+$1->symbol+", ax\n";
				}
				
				else{
					$$->code+= "mov  "+$1->symbol+"[bx], ax\n";
				}
				delete $3;
		
		}	
	   ;
			
logic_expression : rel_expression //complete	
		{$$=$1;
		lout<<"Line No:"<<yylineno<<"logic_expression : rel_expression \n";}
		 | rel_expression LOGICOP rel_expression //1 0r 0
		{
		$$=$1;$$->code+=$3->code;
		
		if($2->getname()=="&&"){
		char* nonmatch=newLabel();
		char* exit=newLabel();
		char* temp=newTemp();
		$$->code+="mov ax,"+$1->symbol+"\n";
		$$->code+="cmp ax,0\n";
		$$->code+="je "+string(nonmatch)+"\n";
		$$->code+="mov ax"+$3->symbol+"\n";
		$$->code+="cmp ax,0\n";
		$$->code+="je "+string(nonmatch)+"\n";
		$$->code+="mov "+string(temp)+",1\n";
		$$->code+="jmp "+string(exit)+"\n";
		$$->code+=string(nonmatch)+" :\n";
		$$->code+="mov" +string(temp)+",0\n";
		$$->code+=string(exit)+":\n";
		}else if($2->getname()=="||"){
		char* match=newLabel();
		char* exit=newLabel();char* temp=newTemp();
		$$->code+="mov ax,"+$1->symbol+"\n";
		$$->code+="cmp ax,0\n";
		$$->code+="jne "+string(match)+"\n";
		$$->code+="mov ax"+$3->symbol+"\n";
		$$->code+="cmp ax,0\n";
		$$->code+="jne "+string(match)+"\n";
		$$->code+="mov "+string(temp)+",0\n";
		$$->code+="jmp "+string(exit)+"\n";
		$$->code+=string(match)+" :\n";
		$$->code+="mov" +string(temp)+",1\n";
		$$->code+=string(exit)+":\n";
		}
		}

		
		 ;
			
rel_expression	: simple_expression //complete
		{
		$$=$1;
	}
		| simple_expression RELOP simple_expression //complete
		{
		
		$$=$1;
		$$->code+=$3->code;
		char* temp=newTemp();
		char* nonmatch=newLabel();
		char* exit=newLabel();
		$$->code+="mov ax,"+$1->symbol+"\n";
		
		$$->code+="mov bx,"+$3->symbol+"\n";
		if($2->getname()==">"){
		$$->code+="cmp ax,bx\n";
		$$->code+="jle "+string(nonmatch)+"\n";//milenai
		$$->code+="mov "+string(temp)+",1\n";
		$$->code+="jmp "+string(exit)+"\n";
		$$->code+=string(nonmatch)+":\n";
		$$->code+="mov "+string(temp)+",0\n";
		$$->code+=string(exit)+":\n";
		$$->symbol=string(temp);
		}else if($2->getname()=="<"){
		
		$$->code+="cmp ax,bx\n";
		$$->code+="jge "+string(nonmatch)+"\n";//milenai
		$$->code+="mov "+string(temp)+",1\n";
		$$->code+="jmp "+string(exit)+"\n";
		$$->code+=string(nonmatch)+":\n";
		
		$$->code+="mov "+string(temp)+",0\n";
		$$->code+=string(exit)+":\n";
		$$->symbol=string(temp);
		}else if($2->getname()=="<="){
		$$->code+="cmp ax,bx\n";
		$$->code+="jg "+string(nonmatch)+"\n";//milenai
		$$->code+="mov "+string(temp)+",1\n";
		$$->code+="jmp "+string(exit)+"\n";
		$$->code+=string(nonmatch)+":\n";
		$$->code+="mov "+string(temp)+",0\n";
		$$->code+=string(exit)+":\n";
		$$->symbol=string(temp);
		}else if($2->getname()==">="){
		$$->code+="cmp ax,bx\n";
		$$->code+="jl "+string(nonmatch)+"\n";//milenai
		$$->code+="mov "+string(temp)+",1\n";
		$$->code+="jmp "+string(exit)+"\n";
		$$->code+=string(nonmatch)+":\n";
		$$->code+="mov "+string(temp)+",0\n";
		$$->code+=string(exit)+":\n";
		$$->symbol=string(temp);
		}else if($2->getname()=="=="){
		$$->code+="cmp ax,bx\n";
		$$->code+="jne "+string(nonmatch)+"\n";//milenai
		$$->code+="mov "+string(temp)+",1\n";
		$$->code+="jmp "+string(exit)+"\n";
		$$->code+=string(nonmatch)+":\n";
		$$->code+="mov "+string(temp)+",0\n";
		$$->code+=string(exit)+":\n";
		$$->symbol=string(temp);
		}else if($2->getname()=="!="){
		$$->code+="cmp ax,bx\n";
		$$->code+="je "+string(nonmatch)+"\n";//milenai
		$$->code+="mov "+string(temp)+",1\n";
		$$->code+="jmp "+string(exit)+"\n";
		$$->code+=string(nonmatch)+":\n";
		$$->code+="mov "+string(temp)+",0\n";
		$$->code+=string(exit)+":\n";
		$$->symbol=string(temp);
		}
		}	
		;
				
simple_expression : term 
		{$$=$1;
		lout<<"Line No:"<<yylineno<<"simple_expression : term \n";}
		  | simple_expression ADDOP term 
		{
		$$=$1;
				$$->code+=$3->code;
				
				// move one of the operands to a register, perform addition or subtraction with the other operand and move the result in a temporary variable  
				char* temp=newTemp();
				if($2->getname()=="+"){
					$$->code+="mov ax,"+$1->symbol+"\n";
					$$->code+="add ax,"+$3->symbol+"\n";
					$$->code+="mov "+string(temp)+",ax\n";
					$$->symbol=string(temp);
					
				
				}
				else{
				$$->code+="mov ax,"+$1->symbol+"\n";
					$$->code+="sub ax,"+$3->symbol+"\n";
					$$->code+="mov "+string(temp)+",ax\n";
					$$->symbol=string(temp);
					
				}
				delete $3;
			}
		
             ;
		  
					
term :	unary_expression
		{
		$$=$1;
		lout<<"Line No:"<<yylineno<<"term:	unary_expression\n";}
     |  term MULOP unary_expression
		{$$=$1;
						$$->code += $3->code;
						$$->code += "mov ax, "+ $1->symbol+"\n";
						$$->code += "mov bx, "+ $3->symbol +"\n";
						char *temp=newTemp();
						if($2->getname()=="*"){
							$$->code += "mul bx\n";
							$$->code += "mov "+ string(temp) + ", ax\n";
						}
						else if($2->getname()=="/"){
							$$->code+="mov dx,0\n";
							$$->code+="div bx\n";
							$$->code+="mov "+string(temp)+",ax\n";
				
							// clear dx, perform 'div bx' and mov ax to temp
						}
						else{
							$$->code+="mov dx,0\n";
							$$->code+="div bx\n";
							$$->code+="mov "+string(temp)+",dx\n";
						}
						$$->symbol=string(temp);
						delete $3;
		
            }
     ;

unary_expression : ADDOP unary_expression  
		{
		$$=$2;
		if($1->getname()=="-"){
		char* temp=newTemp();
		$$->code+="mov ax,"+$2->symbol+"\n";
		$$->code+="neg ax\n";
		$$->code+="mov "+string(temp)+","+"ax\n";
		$$->symbol=string(temp);
		}else{
		$$=$2;
		}

		
		
		}
		 | NOT unary_expression //complete
		{
		$$=$2;
		char* temp=newTemp();
		$$->code+="mov ax,"+$2->symbol+"\n";
		$$->code+="not ax";
		$$->code+="mov "+string(temp)+",ax\n";
		$$->symbol=string(temp);
		
		}
		 | factor //complete
		{
		$$=$1;
		
		}
				

		 ;
	
factor	: variable 
		
		{myytype* po=new myytype();
		$$=po;		
		$$->code=$1->code;
			if($1->id_type!="ARRAY"){
				$$->symbol= $1->symbol;
			}
			
			else{
				char *temp= newTemp();
				$$->code+="mov ax, " + $1->symbol+ "[bx]\n";
				$$->code+= "mov " + string(temp) + ", ax\n";
				$$->symbol=string(temp);
			}}
	| ID LPAREN argument_list RPAREN //function call
		{myytype* temp=new myytype();
		$$=temp;
		$$->code="";
		$$->code+=$3->code;
		for(int i=0;i<function_argument_size_for_use;i++){
		$$->code+="mov ax,"+function_argument_for_use[i]+"\n";
		$$->code+="push ax\n";
		}
		$$->code+="call "+$1->getname()+"\n";
		$$->code+="pop ax\n";
		char *Temp= newTemp();
		$$->code+="mov "+string(Temp)+",ax\n";
		$$->symbol=string(Temp);function_argument_size_for_use=0;

		}
//int z=0;}
	| LPAREN expression RPAREN //a=1+(3+2) //complete
		{
		$$=$2;
		lout<<"Line No:"<<yylineno<<"factor| LPAREN expression RPAREN\n";
		}
		
	| CONST_INT 
		{
		myytype* temp=new myytype();
		char* TEMP=newTemp();
		
		temp->code="mov ax,"+$1->getname()+"\n";
		temp->code+="mov "+string(TEMP)+",ax\n";
		temp->symbol=string(TEMP);
		$$=temp;
		
		}
	| CONST_FLOAT
		{
		}
	| CONST_CHAR
		{
		}
	| variable INCOP //vejal
		{
		myytype* temp=new myytype();
		temp->code=$1->code;
		if($1->id_type!="ARRAY"){
		char* TEMP=newTemp();
		temp->code+="mov ax,"+$1->symbol+"\n";
		temp->code+="mov "+string(TEMP)+",ax\n";
		temp->code+="INC ax";
		temp->code+="mov "+$1->symbol+"ax\n";
		temp->symbol=string(TEMP);
		
		}else{
		char* TEMP=newTemp();
		temp->code+="mov ax,"+$1->symbol+"[bx]\n";
		temp->code+="mov "+string(TEMP)+",ax\n";
		
		temp->code+="INC ax\n";
		temp->code+="mov "+$1->symbol+"[bx], ax\n";
		temp->symbol=string(TEMP);
		}
		$$=temp;
		}
	| variable DECOP //vejal
	{myytype* temp=new myytype();
		temp->code=$1->code;
		if($1->id_type!="ARRAY"){
		char* TEMP=newTemp();
		temp->code+="mov ax,"+$1->symbol+"\n";
		temp->code+="mov "+string(TEMP)+",ax\n";
		temp->code+="dec ax";
		temp->code+="mov "+$1->symbol+"ax\n";
		temp->symbol=string(TEMP);
		
		}else{
		char* TEMP=newTemp();
		temp->code+="mov ax,"+$1->symbol+"[bx]\n";
		temp->code+="mov "+string(TEMP)+",ax\n";
		
		temp->code+="dec ax\n";
		temp->code+="mov "+$1->symbol+"[bx], ax\n";
		temp->symbol=string(TEMP);
		}
		$$=temp;
		}	
	
		;
argument_list : arguments {$$=$1;}
                    |{myytype* temp=new myytype();$$=temp;$$->code="";function_argument_size_for_use=0;}
                    ;
arguments: arguments COMMA logic_expression
	{myytype* temp=new myytype();
	temp->code=$1->code+$3->code;
	function_argument_for_use[function_argument_size_for_use]=$3->symbol;
		function_argument_size_for_use++;$$=temp;

		}
              | logic_expression
	{$$=$1;
	function_argument_for_use[function_argument_size_for_use]=$1->symbol;
		function_argument_size_for_use++;}
              ;


 

%%
int main(int argc,char *argv[])
{
if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	yyin=fopen(argv[1],"r");
	if(yyin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	//yyin=fin;
lout.open("log.txt");
tt.open("dd.txt");
err.open("error.txt");
sym.open("symboltable.txt");
yyparse();
tt<<"total lines"<<yylineno<<"total errors"<<errors<<"\n\n";	
err<<"total errors"<<errors<<"\n\n";	
//fclose(yyin);
return 0;
	
}

