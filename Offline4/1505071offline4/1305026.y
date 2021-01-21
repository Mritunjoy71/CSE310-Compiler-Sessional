%{
#define YYSTYPE SymbolInfo*
#include <stdio.h>
#include <stdlib.h>
//#include "1305026_SymbolTable.h"
#include "my_library.h"

using namespace std;

SymbolTable* table;

int yylex(void);
extern FILE* yyin;
extern int line_count;
extern int error;

string var_type;

string total_code;
string init_code =".MODEL SMALL\n.STACK 100H\n\n.DATA\n";
string decl_code;
string main_code = ".CODE\n\nMAIN PROC\n\nMOV AX, @DATA\nMOV DS, AX\n\n";


SymbolInfo* dummy;

ofstream logfile;
ofstream codefile;
ofstream debugfile;

extern string outdec;
extern string indec;


extern int label_count;
extern int temp_count;


void yyerror(string str)
{
	logfile << "ERROR at Line " << line_count << " : " << str << endl << endl;
	cout << "ERROR at Line " << line_count << " : " << str << endl << endl << endl;
}

int yylex(void);

void warning(string str)
{
	logfile << "WARNING at Line " << line_count << " : " << str << endl << endl;
	cout << "WARNING at Line " << line_count << " : " << str << endl << endl << endl;
}


//OK
SymbolInfo* insertID(SymbolInfo* s)
{
	if(table->look_up(s) != NULL) {yyerror("Multiple Declaration of " + s->name); error++; return NULL;}

	else
	{
		s-> data_type = var_type;

		decl_code += s->name + " DW " + "?\n";
		return table->insert(s);
	}
}


//OK
SymbolInfo* make_array(SymbolInfo* arr, SymbolInfo* size_symbol)
{
	if(table->look_up(arr) != NULL) {yyerror("Multiple Declaration of " + arr->name); error++; return dummy;}


	if(size_symbol->data_type == "float") {yyerror("Array index must be of 'int' type"); return dummy;}

	int sz = size_symbol->intval;
	if(sz < 1) {yyerror("Invalid array size"); error++; return dummy;}


	arr->data_type = var_type;
	arr->arr_size = sz;
	SymbolInfo* s = table->insert(arr);
	s->create_array();

	string arr_code = "";

	arr_code = arr->name + " DW ";
	int length = sz;

	for(int i = 0; i < length-1;i++){
		arr_code += "?, " ;
	}
	arr_code += "?\n";

	decl_code += arr_code;

	return s;
}


//OK DO NOT TOUCH
SymbolInfo* handle_for_loop(SymbolInfo* init_cond, SymbolInfo* loop_cond, SymbolInfo* after_cond, SymbolInfo* body_stmt)
{
	SymbolInfo* s = new SymbolInfo();

	string loop_begin = new_label();
	string loop_end = new_label();

	string code = "";

	code = code + init_cond->code + "\n"; // initial statement

	code = code + loop_begin + ":\n"; // start iteration

	code = code + loop_cond->code + "\n";
	code = code + "MOV AX, " + loop_cond->temp_name + "\n";
	code = code + "CMP AX, 0\n";    // loop condition checking

	code = code + "JE " + loop_end + "\n"; // condition fail
	code = code + body_stmt->code + "\n";
	code = code + after_cond->code + "\n";
	code = code + "JMP " + loop_begin + "\n"; // repeat

	code = code + loop_end + ":\n";

	s-> code = s->code + code;

	return s;
}


//OK DO NOT TOUCH
SymbolInfo* handle_while_loop(SymbolInfo* loop_cond, SymbolInfo* body_stmt)
{
	SymbolInfo* s = new SymbolInfo();

	string loop_begin = new_label();
	string loop_end = new_label();

	string code = "";

	code = code + loop_begin + ":\n"; // start iteration

	code = code + loop_cond->code + "\n";

	code = code + "MOV AX, " + loop_cond->temp_name + "\n";
	code = code + "CMP AX, 0\n";    // loop condition checking

	code = code + "JE " + loop_end + "\n"; // condition fail
	code = code + body_stmt->code + "\n";
	code = code + "JMP " + loop_begin + "\n"; // repeat

	code = code + loop_end + ":\n";

	s-> code = s->code + code;

	while(loop_cond->boolval) {body_stmt;}

	return s;
}



// OK
SymbolInfo* handle_if_else(SymbolInfo* expr, SymbolInfo* stmt_1, SymbolInfo* stmt_2)
{
	SymbolInfo* s = new SymbolInfo();

	string label_false = new_label();
	string label_continue = new_label();

	string code = "";
	code = code + expr->code + "\n";

	code = code + "MOV AX, " + expr->temp_name + "\n";

	code = code + "CMP AX, 0\n";
	code = code + "JE " + label_false + "\n"; //else

	//label_true
	code = code + stmt_1->code + "\n";
	code = code + "JMP " + label_continue + "\n";

	//label_false
	code = code + label_false + ":\n";
	code = code + stmt_2->code + "\n";

	//label_continue
	code = code + label_continue + ":\n";

	s->code = s->code + code;

	return s;
}



//OK
SymbolInfo* handle_if(SymbolInfo* expression, SymbolInfo* statement)
{
	SymbolInfo* s = new SymbolInfo();

	string label_false = new_label();

	string code = "";
	code = code + expression->code + "\n";
	code = code + "MOV AX, " + expression->temp_name + "\n";
	code = code + "CMP AX, 0\n";
	code = code + "JE " + label_false + "\n";
	code = code + statement->code + "\n";
	code = code + label_false + ":\n";

	return s;
}




//OK
SymbolInfo* handle_array_access(SymbolInfo* s1, SymbolInfo* s3)
{
	SymbolInfo* search = table->look_up(s1->name);

	if(search == NULL)
	{
		yyerror(s1->name + " was not declared in this scope");
		error++;
		return dummy;
	}

	else if(search->arr_size == -1)
	{
		yyerror(s1->name + " is not of array type");
		error++;
		return dummy;
	}

	else if(s3->data_type == "float" || s3->data_type == "char")
	{
		yyerror("Array index must be of 'int' type");
		error++;
		return dummy;
	}

	else if(s3->intval < 0 || s3->intval >= search->arr_size)
	{
		yyerror("Array index out of bound");
		error++;
		return dummy;
	}

	return search->get_arr_ptr(s3->intval);

}


//OK
SymbolInfo* handle_id_access(SymbolInfo* s1)
{
	SymbolInfo* search = table->look_up(s1->name);
	if(search != NULL)
	{
		return search;
	}
	else
	{
		yyerror(s1->name + " was not declared in this scope" );
		error++;
		return dummy;
	}
}




//OK
SymbolInfo* handle_assign(SymbolInfo* s1, SymbolInfo* s3)
{
	SymbolInfo* s = new SymbolInfo();

	if(s1->arr_size > 0 || s3->arr_size > 0)
	{
		yyerror("Illegal operation on array");
		error++;
		return s;
	}

	if(s3->data_type == "float" && s1->data_type != "float")
	{
		warning("Casting float into non-float");
	}

	if(s1->data_type == "int")
	{
		if(s3-> data_type == "int")	s1->intval = s3->intval;
		if(s3-> data_type == "float")	s1->intval = s3->floatval;
		if(s3-> data_type == "char")	s1->intval = s3->charval;

		s1->boolval = s3->boolval;

		s-> intval = s1->intval;
		s-> boolval = s1->boolval;
	}


	if(s1->data_type == "float")
	{

		if(s3-> data_type == "int")	s1->floatval = s3->intval;
		if(s3-> data_type == "float")	s1->floatval = s3->floatval;
		if(s3-> data_type == "char")	s1->floatval = s3->charval;

		s1->boolval = s3->boolval;

		s-> floatval = s1->floatval;
		s-> boolval = s1->boolval;
	}

	if(s1->data_type == "float")
	{
		if(s3-> data_type == "int")	s1->charval = s3->intval;
		if(s3-> data_type == "float")	s1->charval = s3->floatval;
		if(s3-> data_type == "char")	s1->charval = s3->charval;

		s1->boolval = s3->boolval;

		s->charval = s1->charval;
		s-> boolval = s1->boolval;
	}

	if(s1->array_index_holder == -1)
	{
		gen_code_assign(s, s1->temp_name, s3->temp_name);

		s->code = s3->code + s1->code + s->code;
	}

	else
	{
		s->code = s3->code + s1->code + s->code;

		s->code = s->code + "LEA DI, " + s1->name + "\n";
		s->code = s->code + "MOV AX, " + s3->temp_name + "\n";

		s->code = s->code + "ADD DI, " + to_string(s1->array_index_holder) +"\n";
		s->code = s->code + "ADD DI, " + to_string(s1->array_index_holder) +"\n";

		s->code = s->code + "MOV [DI], AX\n";
		s->temp_name = new_temp();
	}


	return s;
}





//OK
SymbolInfo* handle_relop_logicop(SymbolInfo* s1, SymbolInfo* s2, SymbolInfo* s3)
{
	//codefile << "Entering primary generator" << endl;
	SymbolInfo* s = new SymbolInfo();

	string op = s2->name;

	s->data_type = "int";
	int temp;
	float x, y;

	if(s1->data_type == "int")		x = s1->intval;
	else if(s1->data_type == "float")	x = s1->floatval;
	else if(s1->data_type == "char")	x = s1->charval;

	if(s3->data_type == "int")		y = s3->intval;
	else if(s3->data_type == "float")	y = s3->floatval;
	else if(s3->data_type == "char")	y = s3->charval;


	if (op==">")		temp = x>y;
	else if(op=="<")	temp = x<y;
	else if(op==">=")	temp = x>=y;
	else if(op=="<=")	temp = x<=y;
	else if(op=="==")	temp = x==y;
	else if(op=="!=")	temp = x!=y;
	else if(op=="&&")	temp = x&&y;
	else if(op=="||")	temp = x||y;


	s->intval = temp;
	s->boolval = temp;

	gen_code_relop_logicop(s, s1->temp_name, op, s3->temp_name); // my_library

	s->code = s3->code + s1->code + s->code;

	return s;
}




//OK
SymbolInfo* handle_addop(SymbolInfo* s1, SymbolInfo* s2, SymbolInfo* s3)
{
	SymbolInfo* s = new SymbolInfo();
	string op = s2->name;

	if(s1->data_type == "float" || s3->data_type == "float") s->data_type = "float";
	else s->data_type = "int";

	if(op == "+")
	{

			if(s1->data_type == "int" && s3->data_type == "int")
			{
				s->intval = s1->intval + s3->intval;
				s->boolval = s->intval;
			}

			else if(s1->data_type == "int" && s3->data_type == "float")
			{
				s->floatval = s1->intval + s3->floatval;
				s->boolval = s->floatval;
			}

			else if(s1->data_type == "float" && s3->data_type == "int")
			{
				s->floatval = s1->floatval + s3->intval;
				s->boolval = s->floatval;
			}

			else if(s1->data_type == "float" && s3->data_type == "float")
			{
				s->floatval = s1->floatval + s3->floatval;
				s->boolval = s->floatval;
			}

			gen_code_addop_plus(s, s1->temp_name, s3->temp_name);
	}

	else if(op=="-")
	{
		if(s1->data_type == "int" && s3->data_type == "int")
		{
			s->intval = s1->intval - s3->intval;
			s->boolval = s->intval;
		}

		else if(s1->data_type == "int" && s3->data_type == "float")
		{
			s->floatval = s1->intval - s3->floatval;
			s->boolval = s->floatval;
		}

		else if(s1->data_type == "float" && s3->data_type == "int")
		{
			s->floatval = s1->floatval - s3->intval;
			s->boolval = s->floatval;
		}

		else if(s1->data_type == "float" && s3->data_type == "float")
		{
			s->floatval = s1->floatval - s3->floatval;
			s->boolval = s->floatval;
		}

		gen_code_addop_minus(s, s1->temp_name, s3->temp_name);
	}

	s->code = s3->code + s1->code + s->code;

	return s;
}





//OK
SymbolInfo* handle_mulop( SymbolInfo* s1, SymbolInfo* s2, SymbolInfo* s3)
{
	SymbolInfo* s = new SymbolInfo();
	string op = s2->name;

	if(op == "%")
	{
		if(s1->data_type == "float"||s3->data_type == "float")
		{
			yyerror("invalid operands of types ‘" +  s1->data_type +  "' and ‘" + s3->data_type + "’ to binary ‘operator%’");
			error++;
		}

		s->intval = s1->intval % s->intval;
		s->boolval = s->intval;

		gen_code_mulop_mod(s, s1->temp_name, s3->temp_name);
	}


	else if(op == "*" || op == "/")
	{
		if(s1->data_type == "float" || s3->data_type == "float") s->data_type = "float";
		else s->data_type = "int";


		if(op == "*")
		{

			if(s1->data_type == "int" && s3->data_type == "int")
			{
				s->intval = s1->intval * s3->intval;
				s->boolval = s->intval;
			}

			else if(s1->data_type == "int" && s3->data_type == "float")
			{
				s->floatval = s1->intval * s3->floatval;
				s->boolval = s->floatval;
			}
			else if(s1->data_type == "float" && s3->data_type == "int")
			{
				s->floatval = s1->floatval * s3->intval;
				s->boolval = s->floatval;
			}

			else if(s1->data_type == "float" && s3->data_type == "float")
			{
				s->floatval = s1->floatval * s3->floatval;
				s->boolval = s->floatval;
			}

			gen_code_mulop_multipliacation(s, s1->temp_name, s3->temp_name);
		}

		else if(op=="/")
		{
			if(s1->data_type == "int" && s3->data_type == "int")
			{
				s->intval = s1->intval / s3->intval;
				s->boolval = s->intval;
			}

			else if(s1->data_type == "int" && s3->data_type == "float")
			{
				s->floatval = s1->intval / s3->floatval;
				s->boolval = s->floatval;
			}

			else if(s1->data_type == "float" && s3->data_type == "int")
			{
				s->floatval = s1->floatval / s3->intval;
				s->boolval = s->floatval;
			}

			else if(s1->data_type == "float" && s3->data_type == "float")
			{
				s->floatval = s1->floatval / s3->floatval;
				s->boolval = s->floatval;
			}

			gen_code_mulop_division(s, s1->temp_name, s3->temp_name);
		}
	}

	s->code = s3->code + s1->code + s->code;

	return s;
}








//OK
SymbolInfo* handle_unary(SymbolInfo* s1, SymbolInfo* s2)
{

	if(s1-> name == "+")
	{
		return s2;
	}



	SymbolInfo* s = new SymbolInfo();
	string t = new_temp();
	s->temp_name = t;

	string code = "";
	string v = s2->temp_name;



	if(s1-> name == "-")
	{
		s-> data_type = s2 -> data_type;
		s-> boolval = s2-> boolval;
		s->intval = -s2->intval;
		s->floatval = -s2->floatval;
		s->charval = -s2->charval;

		code = code + "MOV AX, " + v + "\n";
		code = code + "NEG AX\n";
		code = code + "MOV " + t + ", ax\n";
	}

	else if(s1->name == "!")
	{
		s-> data_type = "int";
		s-> boolval = !(s2-> boolval);

		if(s2->data_type == "int") s-> intval = !(s2->intval);
		else if(s2->data_type == "float") s-> intval = !(s2->floatval);
		else if(s2->data_type == "char") s-> intval = !(s2->charval);

		string L1 = new_label();

		code = code + "MOV AX, " + v + "\n";
		code = code + "CMP AX, 0\n";
		code = code + "JE " + L1 + "\n";

		code = code + "MOV AX, 1\n";

		code = code + L1 + ":\n";
		code = code + "MOV " + t +  ", AX\n";
	}

	s->code = s->code + code;

	return s;
}





//OK
SymbolInfo* handle_incop(SymbolInfo* s1)
{
	SymbolInfo* s = new SymbolInfo();
	s->data_type = s1->data_type;


	if(s1-> data_type == "int")		{s->intval = s1->intval; s1->intval = s1->intval + 1; s->boolval = s->intval;}
	else if(s1-> data_type == "float")	{s->floatval = s1->floatval; s1->floatval = s1->floatval + 1; s->boolval = s->floatval;}
	else if(s1-> data_type == "char") 	{s->charval = s1->charval; s1->charval = s1->charval + 1; s->boolval = s->charval;}

	gen_code_incop(s, s1->temp_name);


	return s;
}




//OK
SymbolInfo* handle_decop(SymbolInfo* s1)
{
	SymbolInfo* s = new SymbolInfo();
	s->data_type = s1->data_type;


	if(s1-> data_type == "int")		{s->intval = s1->intval; s1->intval = s1->intval - 1; s->boolval = s->intval;}
	else if(s1-> data_type == "float")	{s->floatval = s1->floatval; s1->floatval = s1->floatval - 1; s->boolval = s->floatval;}
	else if(s1-> data_type == "char") 	{s->charval = s1->charval; s1->charval = s1->charval - 1; s->boolval = s->charval;}

	gen_code_decop(s, s1->temp_name);


	return s;
}




SymbolInfo* val_print(SymbolInfo* s3)
{

	string dt = s3->data_type;

	if(dt == "int")	cout << "Value of " << s3->name << " = " << s3->intval << endl << endl << endl;
	else if(dt == "float") cout << "Value of " << s3->name << " = " << s3->floatval << endl << endl << endl;
	else if(dt == "char")  cout << "Value of " << s3->name << " = " << s3->charval << endl << endl << endl;

	SymbolInfo* s = new SymbolInfo();
	string code = "";

	if(dt == "int")
	{
		SymbolInfo* s = table->look_up(s3->name);
		string v = s->temp_name;

		code = code + "MOV AX, " + v + "\n";
		code = code + "CALL OUTDEC\n";

		code = code + "MOV AH, 2\n";
		code = code + "MOV DL, 0DH\n";
		code = code + "INT 21H\n";

		code = code + "MOV AH, 2\n";
		code = code + "MOV DL, 0AH\n";
		code = code + "INT 21H\n";
	}

	else if(dt == "char")
	{
		code = code + "MOV AH, 2\n";
		code = code + "MOV DL, 0DH\n";
		code = code + "INT 21H\n";

		code = code + "MOV AH, 2\n";
		code = code + "MOV DL, 0AH\n";
		code = code + "INT 21H\n";

		code = code + "MOV DL, " + s3->temp_name + "\n";
		code = code + "INT 21H\n";
	}

	s-> code = s-> code + code;

	return s;
}




%}



%token CONST_INT CONST_FLOAT CONST_CHAR ID INCOP MULOP ADDOP RELOP LOGICOP ASSIGNOP LPAREN RPAREN RTHIRD LTHIRD LCURL RCURL COMMA SEMICOLON NOT DECOP IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE VOID RETURN SWITCH CASE DEFAULT CONTINUE  STRING MAIN PRINTLN

%error-verbose

%left '+' '-'
%left '*' '/'

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start HAJIME





%%





HAJIME		: var_declaration func_list Program
		| var_declaration  Program
		| func_list Program
		| Program
		;


func_list	: func_list func
		| func
		;


func		: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
		| type_specifier ID LPAREN parameter_list RPAREN compound_statement
		| type_specifier ID LPAREN RPAREN SEMICOLON
		| type_specifier ID LPAREN RPAREN compound_statement
		;


parameter_list	: type_specifier ID
		| type_specifier ID LTHIRD CONST_INT RTHIRD
		| parameter_list COMMA ID LTHIRD CONST_INT RTHIRD
		| parameter_list COMMA ID
		;

func_defns	: type_specifier ID LPAREN parameter_list RPAREN compound_statement func_defns
		| type_specifier ID LPAREN parameter_list RPAREN compound_statement
		;







Program : INT MAIN LPAREN RPAREN compound_statement		{
									logfile << "Program : INT MAIN LPAREN RPAREN compound_statement\n\n";
									$$ = $5;
									main_code = main_code + $$->code;
									main_code = main_code + "MAIN ENDP\n\n";
								}
	| INT MAIN LPAREN RPAREN compound_statement func_defns
	;


compound_statement : LCURL var_declaration statements RCURL	{
								logfile << "compound_statement : LCURL var_declaration statements RCURL\n\n";
								$$ = new SymbolInfo();
								$$->code = $2->code + $3->code;
								}
		   | LCURL statements RCURL			{	logfile << "compound_statement : LCURL statements RCURL\n\n"; $$ = $2;}
		   | LCURL RCURL				{
		   							logfile << "compound_statement : LCURL RCURL\n\n";
		   							$$ = dummy;
		   						}
		   ;


var_declaration	: type_specifier declaration_list SEMICOLON	{
								logfile << "var_declaration : type_specifier declaration_list SEMICOLON\n\n";
								$$ = $2;
								delete $1;
								}
		|  var_declaration type_specifier declaration_list SEMICOLON	{
				logfile << "var_declaration :   var_declaration type_specifier declaration_list SEMICOLON\n\n";

				$$ = new SymbolInfo();
				$$->code = $1->code + $3->code;
				delete $2;
				}
		;

type_specifier	: INT	{logfile << "type_specifier : INT\n\n"; var_type = "int"; $$ = new SymbolInfo("int", "type");}
		| FLOAT	{logfile << "type_specifier : FLOAT\n\n"; var_type = "float"; $$ = new SymbolInfo("float", "type");}
		| CHAR	{logfile << "type_specifier : CHAR\n\n"; var_type = "char"; $$ = new SymbolInfo("char", "type");}
		| VOID  {;}
		;

declaration_list : declaration_list COMMA ID	{logfile << "declaration_list : declaration_list COMMA ID\n" + $3->name +"\n\n"; $$=insertID($3);}
		 | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD	{
		 		logfile << "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n" + $3->name + "\n\n";
				$$ = make_array($3, $5);
		 		}
		 | ID	{
			logfile << "declaration_list : ID\n" + $1->name +"\n\n";
			$$ = insertID($1);
		 	}
		 | ID LTHIRD CONST_INT RTHIRD	{
						logfile << "declaration_list : ID LTHIRD CONST_INT RTHIRD\n" +  $1->name +"\n\n";
						$$ = make_array($1, $3);
						}
		 | ID error LTHIRD error RTHIRD
		 ;

statements : statement				{logfile << "statements : statement\n\n"; $$ = $1;}
	   | statements statement		{
	   						logfile << "statements : statements statement\n\n";
	   						$$ = new SymbolInfo();
	   						$$->code = $1->code + $2->code;
	   						delete $2;
	   					}
	   ;


statement  : expression_statement		{logfile << "statement : expression_statement\n\n"; $$ = $1;}
	   | compound_statement			{logfile << "statement : compound_statement\n\n"; $$ = $1;}
	   | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{
	  		 logfile << "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n";
	  		 $$ = handle_for_loop($3, $4, $5, $7);
	  	 }
	   | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE	{
	   			logfile << "statement : IF LPAREN expression RPAREN statement\n\n";
				$$ = handle_if($3, $5);
	   			}
	   | IF LPAREN expression RPAREN statement ELSE statement	{
	   			logfile << "statement : IF LPAREN expression RPAREN statement ELSE statement\n\n";
	   	 		$$ = handle_if_else($3, $5, $7);
	   			}
	   | WHILE LPAREN expression RPAREN statement	{
	   							logfile << "statement : WHILE LPAREN expression RPAREN statement\n\n";
	   							 $$ = handle_while_loop($3, $5);
	   						}
	   | PRINTLN LPAREN ID RPAREN SEMICOLON		{
	   							logfile << "statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n";
	   							$$ = val_print($3);
	   						}
	   | RETURN expression SEMICOLON		{
	   							logfile << "statement : RETURN expression SEMICOLON\n\n";

	   							$$ = new SymbolInfo("return", "return");
	   							$$->code = "\n\n;exit to dos\nMOV AH, 4ch\nINT 21H\n";
	   						}
	   | RETURN expression error SEMICOLON
	   | FOR error LPAREN error expression_statement error expression_statement error expression error RPAREN error statement
	   | WHILE error LPAREN error RPAREN error statement
	   | IF error LPAREN error RPAREN statement
	   | IF error LPAREN error RPAREN error statement error ELSE error statement
	   ;

expression_statement	: SEMICOLON			{
								logfile << "expression_statement : SEMICOLON\n\n";
								$$ = new SymbolInfo(";", "SEMICOLON");
							}
			| expression SEMICOLON		{logfile << "expression_statement : expression SEMICOLON\n\n"; $$ = $1;}
			| expression error SEMICOLON
			;

variable : ID						{
								logfile << "variable : ID\n" + $1->name + "\n\n";
								$$ = handle_id_access($1);
							}
	 | ID LTHIRD expression RTHIRD			{
	 							logfile << "variable : ID LTHIRD expression RTHIRD\n" + $1->name + "\n\n";
	 							$$ = handle_array_access($1, $3);
	 						}
	 | ID LTHIRD expression error RTHIRD
	 ;

expression : logic_expression				{
								logfile << "expression : logic_expression\n\n";
								$$ = $1;
							}
	   | variable ASSIGNOP logic_expression		{
	   							logfile << "expression : variable ASSIGNOP logic_expression\n\n";
	   							$$ = handle_assign($1, $3);
	   							table->print_table();
	   						}
	   | variable ASSIGNOP error logic_expression
	   ;

logic_expression : rel_expression			{
								logfile << "logic_expression : rel_expression\n\n";
								$$ = $1;
							}
		 | rel_expression LOGICOP rel_expression{
		 						logfile << "logic_expression : rel_expression LOGICOP rel_expression\n\n";
								$$ =  handle_relop_logicop($1, $2, $3);
							}
		 | rel_expression LOGICOP error rel_expression
		 ;

rel_expression	: simple_expression			{logfile << "rel_expression : simple_expression\n\n"; $$ = $1;}
		| simple_expression RELOP simple_expression	{
								logfile<< "rel_expression : simple_expression RELOP simple_expression\n\n";
								$$ = handle_relop_logicop($1, $2, $3);
								}
		| simple_expression RELOP error simple_expression
		;

simple_expression : term				{logfile << "simple_expression : term\n\n"; $$ = $1;}
		  | simple_expression ADDOP term	{
		  						logfile << "simple_expression : simple_expression ADDOP term\n\n";
		  						$$ = handle_addop($1, $2, $3);
		  					}
		  | simple_expression ADDOP error term
		  ;

term :	unary_expression	{logfile << "term : unary_expression\n\n"; $$ = $1;}
     |  term MULOP unary_expression	{logfile << "term : term MULOP unary_expression\n\n"; $$ = handle_mulop($1, $2, $3);}
     |  term MULOP error unary_expression
     ;

unary_expression : ADDOP unary_expression	{logfile << "unary_expression : ADDOP unary_expression\n\n"; $$ = handle_unary($1, $2);}
		 | NOT unary_expression	{logfile << "unary_expression : NOT unary_expression\n\n"; $$ = handle_unary($1, $2);}
		 | factor	{logfile << "unary_expression : factor\n\n"; $$ = $1;}
		 | ADDOP error unary_expression
		 | NOT error unary_expression
		 ;

factor	: variable	{
				logfile << "factor : variable" << endl << endl;

				 if($1->array_index_holder == -1) $$ = $1;

				 else
				 {
				 	$$ = new SymbolInfo();

				 	string t = new_temp();
				 	$$->temp_name = t;

				 	string code = "";

				 	code = code + "LEA DI, " + $1->name + "\n";
				 	code = code + "ADD DI, " + to_string($1->array_index_holder) + "\n";
				 	code = code + "ADD DI, " + to_string($1->array_index_holder) +" \n";
				 	code = code + "MOV AX, [DI]\n";
				 	code = code + "MOV " + t + ", AX\n";

				 	$$-> code = $$->code + code;

				 	$$->intval = $1->intval;
				 	$$->floatval = $1->floatval;
				 	$$->charval = $1->charval;

				 	$$->data_type = $1->data_type;
				 }
			}
	| LPAREN expression RPAREN	{logfile << "factor : LPAREN expression RPAREN" << endl << endl; $$ = $2;}
	| CONST_INT	{logfile << "factor : CONST_INT\n" << $1->name << endl << endl; $$ = $1;}
	| CONST_FLOAT	{logfile << "factor : CONST_FLOAT\n"  << $1->name << endl << endl; $$ = $1;}
	| CONST_CHAR	{logfile << "factor : CONST_CHAR\n"  << $1->name << endl << endl; $$ = $1;}
	| factor INCOP	{logfile << "factor : factor INCOP\n\n"; $$ = handle_incop($1);}
	| factor DECOP	{logfile << "factor : factor DECOP\n\n"; $$ = handle_decop($1);}
	| LPAREN error expression error RPAREN
	| LPAREN expression error RPAREN
	| LPAREN error expression RPAREN
	;
%%
int main(int argc, char const* argv[])
{
	logfile.open("1305026_log.txt");
	codefile.open("code.asm"); // 8086 code goes in here
	debugfile.open("debug.txt");

	table = new SymbolTable(31);
	logfile << "\n";
	yyin = fopen(argv[1], "r");
	dummy = new SymbolInfo();
	decl_code = "\n";

	cout << "##############################################################################" << endl;
	cout << "##############################################################################" << endl;

   	yyparse();

   	logfile << "\t\t symbol table:\n";
 	table->print_table();
 	logfile << endl;
 	logfile << "Total Lines: " << line_count << endl << endl;
 	logfile << "Total Errors: " << error << endl << endl;

 	decl_code = decl_code + "\n\n";

 	total_code = init_code + decl_code + main_code;
 	total_code = total_code + "\n" + outdec + "\nEND MAIN\n";
 	codefile << total_code << endl;

	cout << temp_count << endl;

   	exit(0);
}
