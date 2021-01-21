%option noyywrap

%{
#include<stdio.h>
#include<stdlib.h>

int line_count=1;

FILE *logout;
FILE *tokenout;

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
NEWLINE \n

%%

{NEWLINE} {line_count++;}

"if"	{
			fprintf(tokenout,"<IF>");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n",line_count,yytext);
		}
		
"else"	{
			fprintf(tokenout,"<ELSE>");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n",line_count,yytext);
		}

"int"			{
							fprintf(tokenout,"<INT>");
						fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n",line_count,yytext);
					}

{DIGIT}+ 	{
				fprintf(tokenout,"<CONST_INT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)
			}



[a-zA-Z_][a-zA-Z0-9_]*  {
							fprintf(tokenout,"<ID,%s>",yytext);
							fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\nSS",line_count,yytext);
							//insert in symbol table and print symbol table content(only non empty buckets						
						
						}


"+"		|

"-"		{
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"{"					{
							fprintf(tokenout,"<LCURL>");
						fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n",line_count,yytext);
					}

"}"					{
							fprintf(tokenout,"<RCURL>");
						fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n",line_count,yytext);
					}

"("					{
							fprintf(tokenout,"<LPAREN>");
						fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n",line_count,yytext);
					}

")"					{
							fprintf(tokenout,"<RPAREN>");
						fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n",line_count,yytext);
					}

"="					{
							fprintf(tokenout,"<ASSIGNOP>");
						fprintf(logout,"Line no %d: TOKEN <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
					}
","             {
						fprintf(tokenout,"<COMMA,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n",line_count,yytext);
							//insert in symbol table and print symbol table content(only non empty buckets		
				  }


";"             {
						fprintf(tokenout,"<SEMICOLON,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n",line_count,yytext);
							//insert in symbol table and print symbol table content(only non empty buckets		
				  }


		



			

%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("log.txt","w");
	tokenout= fopen("token.txt","w");

	yyin= fin;
	yylex();
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
