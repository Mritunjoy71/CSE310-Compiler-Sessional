%option noyywrap
%x STRING_LITERAL
%x MULTIPLE_LINE_COMMENT
%x MULTIPLE_LINE_COMMENT_ERROR
%x SINGLE_LINE_COMMENT

%{
#include "SymTable.h"
#include "y.tab.h"

int lCount = 1, errCount = 0;

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

{WHITESPACE}   ;

{NEWLINE} {lCount++;}

"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"int" {return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"char" {return CHAR;}
"return" {return RETURN;}
"void" {return VOID;}
"println"	{return PRINTLN;}

"break" {return BREAK;}
"switch" {return SWITCH;}
"do" {return DO;}
"case" {return CASE;}
"continue" {return CONTINUE;}
"default"	{return DEFAULT;}



{ADDOP} { 
			SymbolInfo *s= new  SymbolInfo(yytext, "ADDOP");
			yylval.symVal= s;
			return ADDOP;
		}



{MULOP}	{
			SymbolInfo *s= new  SymbolInfo(yytext,"MULOP");
			yylval.symVal= s;
			return MULOP;
		}

        
"=" 	{   
            return ASSIGNOP;
        }

{RELATIONAL_OP}  {
		            SymbolInfo *s= new  SymbolInfo(yytext, "RELOP");
		            yylval.symVal= s;
		            return RELOP;
	             }

"&&"	|
"||"	{
			SymbolInfo *s= new  SymbolInfo(yytext,"LOGICOP");
			yylval.symVal= s;
			return LOGICOP;
		}
"!"		{	return NOT; }


";" 	{ return SEMICOLON;}
"," 	{return COMMA;}
"(" 	{return LPAREN;}
")" 	{return RPAREN;}
"{" 	{return LCURL;}
"}" 	{return RCURL;}
"[" 	{return LTHIRD;}
"]" 	{return RTHIRD;}
"++" 	{return INCOP;}
"--" 	{return DECOP;}
        		
		
		
{INTIZER_NUMBER} 	{
                            SymbolInfo *s= new  SymbolInfo(yytext,"CONST_INT");
			                yylval.symVal= s;
			                return CONST_INT;
				
			        }

{FLOAT_NUMBER}      {
                            SymbolInfo *s= new  SymbolInfo(yytext,"CONST_FLOAT");
		                    yylval.symVal= s;
		                    return CONST_FLOAT;
			                     
                    }


{CHARACTER_LITERAL}  {
				            string name;
			                name.push_back(yytext[1]);
			                SymbolInfo* s =new SymbolInfo(name, "CONST_CHAR");
			                yylval.symVal= s;
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
		                    return CONST_CHAR;          
				    }


{IDENTIFIER}        {
							SymbolInfo *s= new  SymbolInfo(yytext,"ID");
			                yylval.symVal= s;
			                return ID;
			        }


\"      { 
			BEGIN STRING_LITERAL;		
		} 
		                          				  
<STRING_LITERAL>{NEWLINE}     {
	                                 lCount++;
	                                 errCount++;
                                     BEGIN INITIAL;					                            
                                }
			

<STRING_LITERAL>\"        {			                       
			                      BEGIN INITIAL;
			                      return STRING;
			                        
			               }	
					
<STRING_LITERAL>[^\"\n]+     {
                                        
			                   }

<STRING_LITERAL>[^\"\n]*\\\n  {
                                        
			                            lCount++;
                                }	
                                		         
<STRING_LITERAL>[^\"\n\\]+\n   {
		                            errCount++;
		                            BEGIN INITIAL;
			         } 		
			         	
                    		         	          				  

"//"             {
					       BEGIN SINGLE_LINE_COMMENT;
							    
                     }
                  
<SINGLE_LINE_COMMENT>[^\n\/]+[\\]\n    {
					                    lCount++;
				                       } 
                  
<SINGLE_LINE_COMMENT>[^\n\\]*    {

				                  }

<SINGLE_LINE_COMMENT>\n   {
					                    
					                    lCount++;
					                    BEGIN INITIAL;
					                    return COMMENT; 
				                  }  				                       				                               


"/*"     {    
                  
                BEGIN(MULTIPLE_LINE_COMMENT);
                
         }   
<MULTIPLE_LINE_COMMENT>[^*\n]* {
                                      
                               }
                               
<MULTIPLE_LINE_COMMENT>[^*\n]*\n     {                         
                                            lCount++;
                                      }
                        
<MULTIPLE_LINE_COMMENT>"*"+[^*/\n]*  {
                                           
                                      }
        
<MULTIPLE_LINE_COMMENT>"*"+[^*/\n]*\n   {                                                                          
                                                lCount++;
                                         }

<MULTIPLE_LINE_COMMENT>[*]+\/   {             
                                    BEGIN(INITIAL);
                                    return COMMENT; 
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
                           

  
%%


