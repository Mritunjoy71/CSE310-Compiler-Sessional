%option noyywrap
%x STRING_LITERAL
%x MULTIPLE_LINE_COMMENT
%x MULTIPLE_LINE_COMMENT_ERROR
%x SINGLE_LINE_COMMENT

%{
#include<bits/stdc++.h>
#include"SymTable.h"
#include "y.tab.h"

int line_no = 1, errCount = 0;
string pp="";


%}

WHITESPACE [ \t\f\r\v]+ 
DIGIT [0-9]
NEWLINE \n
ADDOP [+-] 
MULOP [*/%]
LETTER [a-zA-Z]
CHARACTER_LITERAL '[a-zA-Z0-9]'
CHARACTER_EXCEPTION '\\[nt\"afrbv0]'
FLOAT_NUMBER {DIGIT}*("."{DIGIT}+)?([eE][-+]?{DIGIT}+)?
INTIZER_NUMBER {DIGIT}+
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
RELATIONAL_OP "<"|"<="|">"|">="|"=="|"!="
SINGLE_COMMENT "//".*$

TOO_MANY_DECIMAL_POINT_ERROR {DIGIT}*"."{DIGIT}*((".")+{DIGIT}*)+
ILL_FORMED_NUMBER {DIGIT}*(("."{DIGIT}*)*)?([eE][-+]?{DIGIT}*("."{DIGIT}*)+)+
NUMERIC_CONST {DIGIT}*("."{DIGIT}+)?([eE][-+]?{DIGIT}+)?
INVALID_SUFFIX_ON_NUMBER_OR_PREFIX_ON_IDENTIFIER {NUMERIC_CONST}{IDENTIFIER}
MULTI_CHAR_ERROR '..+'
UNFINISHED_CHAR '[A-Za-z0-9]*|'[\\]'
UNRECOGNIZED_CHAR ''


%%

{WHITESPACE}  { pp=pp+yytext;}

{NEWLINE} {
    pp=pp+yytext;
    line_no++;
   }

"if" {
return IF;
}
"else" {
pp=pp+yytext;
return ELSE;}
"for" {
pp=pp+yytext;
return FOR;}
"while" {
pp=pp+yytext;
return WHILE;}
"int" {
pp=pp+yytext;
return INT;}
"float" {
pp=pp+yytext;
return FLOAT;}
"double" {
pp=pp+yytext;
return DOUBLE;}
"char" {
pp=pp+yytext;
return CHAR;}
"return" {
pp=pp+yytext;
return RETURN;}
"void" {
pp=pp+yytext;
return VOID;}
"println"	{
pp=pp+yytext;
return PRINTLN;}

"break" {
pp=pp+yytext;
return BREAK;}
"switch" {
pp=pp+yytext;
return SWITCH;}
"do" {
pp=pp+yytext;
return DO;}
"case" {
pp=pp+yytext;
return CASE;}
"continue" {
pp=pp+yytext;
return CONTINUE;}
"default"	{
pp=pp+yytext;
return DEFAULT;}



{ADDOP} { 
			SymbolInfo * s = new SymbolInfo(yytext, "ADDOP");
			yylval.symVal = s;	
			pp=pp+yytext;		
			return ADDOP;
		}



{MULOP}	{
			SymbolInfo* s = new SymbolInfo(yytext,"MULOP");
			yylval.symVal = s;	
			pp=pp+yytext;			
			return MULOP;
		}

        
"=" 	{   
            pp=pp+yytext;
            return ASSIGNOP;
        }

{RELATIONAL_OP}  {
                    SymbolInfo* s = new SymbolInfo(yytext, "RELOP");
			        yylval.symVal = s; 
			        pp=pp+yytext;	
		            return RELOP;
	             }

"&&"	|
"||"	{
            SymbolInfo* s = new SymbolInfo(yytext, "LOGICOP");
			yylval.symVal = s; 
			pp=pp+yytext;	            			
			return LOGICOP;
		}
"!"		{	
            pp=pp+yytext;            
            return NOT; 
         }


";" 	{ 
            pp=pp+yytext;
            return SEMICOLON;
         }
"," 	{
            pp=pp+yytext;
            return COMMA;
         }
"(" 	{
            pp=pp+yytext;
            return LPAREN;
        }
")" 	{
            pp=pp+yytext;
            return RPAREN;
         }
"{" 	{
            pp=pp+yytext;
            return LCURL;
         }
"}" 	{
            pp=pp+yytext;
            return RCURL;
        }
"[" 	{
            pp=pp+yytext;
            return LTHIRD;
        }
"]" 	{
            pp=pp+yytext;
            return RTHIRD;
        }
"++" 	{
            pp=pp+yytext;
            return INCOP;
        }
"--" 	{
            pp=pp+yytext;
            return DECOP;
        }
        		
		
		
{INTIZER_NUMBER} 	{
                            SymbolInfo *s =new  SymbolInfo(yytext, "CONST_INT");
                            yylval.symVal= s;
                            pp=pp+yytext;
			                return CONST_INT;
				
			        }

{FLOAT_NUMBER}      {
                            SymbolInfo* s =new  SymbolInfo(yytext, "CONST_FLOAT");
		                	yylval.symVal = s;
		                	pp=pp+yytext;
		                    return CONST_FLOAT;
			                     
                    }


{CHARACTER_LITERAL}  {
				            string name;
			                name.push_back(yytext[1]);
			                SymbolInfo* s =new SymbolInfo(name, "CONST_CHAR");
			                yylval.symVal= s;
			                pp=pp+yytext;
			                return CONST_CHAR;
				     }

{CHARACTER_EXCEPTION} {
					        char ch;
                            switch(yytext[2]){
                                case 'n': ch = '\n'; break;
                                case 't': ch = '\t'; break;
                                case 'v': ch = '\v'; break;
                                case 'a': ch = '\a'; break;
                                case 'f': ch = '\f'; break;
                                case 'r': ch = '\r'; break;
                                case 'b': ch = '\b'; break;
                                case '0': ch = '\0'; break;
                                default: break;			
                            }
                            
			                yytext[0] = ch;
			                yytext[1] = '\0';
			                SymbolInfo *s= new  SymbolInfo(yytext,"CONST_CHAR");
		                    yylval.symVal= s;
			                pp=pp+yytext;
		                    return CONST_CHAR;          
				    }


{IDENTIFIER}        {
                            SymbolInfo* s =new  SymbolInfo(yytext, "ID");
			                yylval.symVal= s;
			                pp=pp+yytext;
			                return ID;
			        }


\"      { 
			BEGIN STRING_LITERAL;
			pp=pp+yytext;		
		} 
		                          				  
<STRING_LITERAL>{NEWLINE}     {
	                                 line_no++;
	                                 errCount++;
	                                 pp=pp+yytext;
                                     BEGIN INITIAL;					                            
                                }
			

<STRING_LITERAL>\"        {			                       
			                      BEGIN INITIAL;
			                      pp=pp+yytext;
			                      return STRING;
			                        
			               }	
					
<STRING_LITERAL>[^\"\n]+    {
                                 pp=pp+yytext;       
			                }

<STRING_LITERAL>[^\"\n]*\\\n  {
                                        pp=pp+yytext;
			                            line_no++;
                              }	
                                		         
<STRING_LITERAL>[^\"\n\\]+\n   {
                                    pp=pp+yytext;
		                            errCount++;
		                            BEGIN INITIAL;
			                   } 		
			         		         	          				  

"//"             {
					       BEGIN SINGLE_LINE_COMMENT;
							    
                  }
                  
<SINGLE_LINE_COMMENT>[^\n\/]+[\\]\n    {
					                    line_no++;
				                       } 
                  
<SINGLE_LINE_COMMENT>[^\n\\]*    {

				                  }

<SINGLE_LINE_COMMENT>\n   {
					                    
					                    line_no++;
					                    BEGIN INITIAL;
					                    //return COMMENT; 
				                  }  				                       				                               


"/*"     {    
                  
                BEGIN(MULTIPLE_LINE_COMMENT);
                
         }   
<MULTIPLE_LINE_COMMENT>[^*\n]* {
                                      
                               }
                               
<MULTIPLE_LINE_COMMENT>[^*\n]*\n     {                         
                                            line_no++;
                                      }
                        
<MULTIPLE_LINE_COMMENT>"*"+[^*/\n]*  {
                                           
                                      }
        
<MULTIPLE_LINE_COMMENT>"*"+[^*/\n]*\n   {                                                                          
                                                line_no++;
                                         }

<MULTIPLE_LINE_COMMENT>[*]+\/   {             
                                    BEGIN(INITIAL);
                                    //return COMMENT; 
                    }                                                          

<MULTIPLE_LINE_COMMENT><<EOF>>     {
                                            errCount++;
                                      }                 
                                        
                    

                                                                 
{TOO_MANY_DECIMAL_POINT_ERROR}  {
                                      errCount++;


                           }

{ILL_FORMED_NUMBER}  {
                               errCount++;    
                     }


{INVALID_SUFFIX_ON_NUMBER_OR_PREFIX_ON_IDENTIFIER}   {
                             errCount++;   
                            } 
                                
                                
                                
{MULTI_CHAR_ERROR}          {
                                   errCount++;
                            }   
                            
 
{UNFINISHED_CHAR}          {
                                   errCount++;
                            }  


{UNRECOGNIZED_CHAR}      {
                                    errCount++;
                          }
.		{
			errCount++;
		}      
		
<<EOF>> {return 0;}		                    
                           

  
%%


