%option noyywrap
%x STRING_LITERAL
%x MULTIPLE_LINE_COMMENT
%x MULTIPLE_LINE_COMMENT_ERROR

%{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int line_count=1;
int line =0;
int error=0;
string yy="";

FILE *logout;
FILE *tokenout;

int bucket_size=7;
int Count =0;
class ScopeTable;
ScopeTable *present=NULL;
class SymbolInfo
{
private:
    string symbol_name;
    string symbol_type;
public:
    SymbolInfo *next;
    SymbolInfo *prev;

    SymbolInfo()
    {
        this->symbol_name="";
        this->symbol_type="";
        this->next=NULL;
        this->prev=NULL;
    }

    ~SymbolInfo()
    {
        delete prev;
        delete next;
    }

    void set_name_type(string symbol_name,string symbol_type)
    {
        this->symbol_name=symbol_name;
        this->symbol_type=symbol_type;
    }

    string get_symbol_name()
    {
        return this->symbol_name;
    }

    string get_symbol_type()
    {
        return this->symbol_type;
    }
};

class ScopeTable
{
public:
    ScopeTable *parentScope;
    int st_id;
    SymbolInfo **htable, **top;
    ScopeTable(int bucket_size)
    {
        Count++;
        this->st_id=Count;
        this->parentScope=present;
        htable = new SymbolInfo*[bucket_size];
        top = new SymbolInfo*[bucket_size];
        for (int i = 0; i < bucket_size; i++)
        {
            htable[i] = NULL;
            top[i] = NULL;
        }
    }
    ~ScopeTable()
    {
        delete [] htable;
    }

    int HashFunc1(string  key)
    {
        int seed = 123;
        unsigned long index = 0;
        for(int i = 0; i < key.length(); i++)
        {
            index = (index * seed) + key[i];
        }
        return index % bucket_size;
    }

    bool Insert(string symbol_name, string symbol_type)
    {
        SymbolInfo *si=Lookup(symbol_name);
        if(!si)
        {
            int hash_val = HashFunc1(symbol_name);
            SymbolInfo *entry = htable[hash_val];
            int pos=0;
            if (entry == NULL)
            {
                entry = new SymbolInfo;
                entry->set_name_type(symbol_name,symbol_type);
                entry->next = NULL;
                entry->prev = NULL;
                htable[hash_val] = entry;
                top[hash_val] = entry;
               // printf("    Inserted in ScopeTable #%d at position %d,%d\n",this->st_id,hash_val,pos);
            }
            else
            {
                while (entry != NULL)
                {
                    entry = entry->next;
                    pos++;
                }
                entry = new SymbolInfo;
                entry->set_name_type(symbol_name,symbol_type);
                entry->next = NULL;
                entry->prev = top[hash_val];
                top[hash_val]->next = entry;
                top[hash_val] = entry;
               // printf("    Inserted in ScopeTable #%d at position %d,%d\n",this->st_id,hash_val,pos);
            }
            return true;
        }
        else
        {
            //cout<<"    Already inserted\n";
            return false;
        }
    }

    void  Delete(string name)
    {

        SymbolInfo* entry;
        string symbol_name=name;
        int hash_val = HashFunc1(symbol_name);
        entry= htable[hash_val];

        while (entry != NULL)
        {
            if(entry->get_symbol_name()==symbol_name)
            {
                if(entry->prev==NULL &&entry->next!=NULL)
                {
                    entry->next->prev=NULL;
                    htable[hash_val]=entry->next;
                    delete entry;
//                    cout<<"     The token is deleted\n";
                    break;
                }
                if(entry->prev!=NULL && entry->next!=NULL)
                {
                    entry->prev->next=entry->next;
                    entry->next->prev=entry->prev;
                    delete entry;
  //                  cout<<"     The token is deleted\n";
                    break;
                }
                if (entry->next == NULL)
                {
                    if (entry->prev == NULL)
                    {
                        htable[hash_val] = NULL;
                        top[hash_val] = NULL;
                        delete entry;
    //                    cout<<"     The token is deleted\n";
                        break;
                    }
                    else
                    {
                        top[hash_val] = entry->prev;
                        top[hash_val]->next = NULL;
                        delete entry;
//                        cout<<"     The token is deleted\n";
                        entry = top[hash_val];
                    }
                }
            }
            entry = entry->next;
        }
    }

    SymbolInfo* Lookup(string symbol_name)
    {
        int hash_val = HashFunc1(symbol_name);
        SymbolInfo* sinfo=new SymbolInfo();
        sinfo= htable[hash_val];
        if (sinfo != NULL)
        {
            int l=0;
            while (sinfo != NULL)
            {
                if (sinfo->get_symbol_name() == symbol_name)
                {
                   // cout<<"     Found  in ScopeTable #"<<this->st_id<<" at position "<<hash_val<<" , "<<l<<"\n";
                    return sinfo;
                }
                l++;
                sinfo=sinfo->next;
            }
        }
        return  0;
    }

    void Print()
    {
        int i;
        fprintf(logout,"ScopeTable #%d\n",this->st_id);
        for(i=0; i<bucket_size; i++)
        {
            if(top[i]!=NULL)
            {
                SymbolInfo *temp=htable[i];
                fprintf(logout,"%d -->",i);
                while(temp)
                {
		            std::string s = "<" + temp->get_symbol_name() + "," + temp->get_symbol_type() + ">    ";
		            char a[200];
		            strcpy(a,s.c_str());
		            a[sizeof(a) - 1] = 0;
		            fprintf(logout,"%s",a);

                    temp=temp->next;
                }
                fprintf(logout,"\n");
            }
            
        }
    }
};

class SymbolTable
{
public:
    ScopeTable *curScope;
    SymbolTable()
    {
        curScope=NULL;
    }
    ~SymbolTable()
    {
        delete curScope;
    }
    void Enter_scope()
    {
        ScopeTable *st  =new ScopeTable(bucket_size);
        st->parentScope=present;
        this->curScope=st;
        present=curScope;
    }
    void Exit_scope()
    {
        if(curScope==NULL)
        {
//             cout<<"    There is no ScopeTable to remove\n";
             return ;
        }
        else if(curScope->parentScope==NULL)
        {
//            cout<<"     ScopeTable with id "<<Count<<" is removed\n";
            delete curScope;
            curScope=NULL;
            present=NULL;
            Count--;
        }
        else
        {
//            cout<<"     ScopeTable with id "<<Count<<" is removed\n";
            present=curScope->parentScope;
            delete curScope;
            curScope=present;
            Count--;
        }
    }

    bool Insert(string symbol_name,string symbol_type)
    {
        bool insrt;
        insrt=curScope->Insert(symbol_name,symbol_type);
        return insrt;
    }
    void Remove(string symbol_name)
    {
        this->curScope->Delete(symbol_name);
    }

    SymbolInfo* Look_up(string symbol_name)
    {
        SymbolInfo *si;
        si=this->curScope->Lookup(symbol_name);
        return si;

    }

    void Print_cur_ScopeTable()
    {
        if(curScope!=NULL)
            this->curScope->Print();

    }

    void Print_all_ScopeTable()
    {
        ScopeTable *temp=this->curScope;
        while(temp!=NULL)
        {
            temp->Print();
            if(temp->parentScope==NULL)
            {
                break;
            }
            else
                temp=temp->parentScope;
        }
    }
};
class SymbolTable;
SymbolTable *syt=new SymbolTable();

void table (string name,string type )
{
    bool insrt;
    insrt= syt->Insert(name,type);
    if(insrt)
    {
        syt->Print_all_ScopeTable();
    }
   
}





%}

WHITESPACE [ \t\f\r\v]+ 
DIGIT [0-9]
NEWLINE \n
LETTER [a-zA-Z]
CHARACTER_LITERAL '[a-zA-Z0-9]'
CHARACTER_LITERAL_EXCEPTION '\\[nt\''afrbv0]'
FLOAT_NUMBER {DIGIT}*("."{DIGIT}+)?([eE][-+]?{DIGIT}+)?
INTIZER_NUMBER {DIGIT}+
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
RELATIONAL_OP "<"|"<="|">"|">="|"=="|"!="
SINGLE_COMMENT "//".*
SINGLE_LINE_STRING \"([^\"\n])*\"


TOO_MANY_DECIMAL_POINT_ERROR {DIGIT}*"."{DIGIT}*((".")+{DIGIT}*)+
ILL_FORMED_NUMBER {DIGIT}*(("."{DIGIT}*)*)?([eE][-+]?{DIGIT}*("."{DIGIT}*)+)+
NUMERIC_CONST {DIGIT}*("."{DIGIT}+)?([eE][-+]?{DIGIT}+)?
INVALID_SUFFIX_ON_NUMBER_OR_PREFIX_ON_IDENTIFIER {NUMERIC_CONST}{IDENTIFIER}
MULTI_CHAR_ERROR '..+'
UNFINISHED_CHAR '[A-Za-z0-9]*|'[\\]'
UNRECOGNIZED_CHAR ''
UNFINISHED_STR \"([^\"\n])*\n
UNFINISHED_MUL_STR \"(([^\"\n])*|"\\\n")*



%%

{NEWLINE} {line_count++;}
{WHITESPACE}  {
				
			  }

"if"	{
			fprintf(tokenout,"<IF>\n");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n\n",line_count,yytext);
		}
		
"else"	{
			fprintf(tokenout,"<ELSE>\n");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n\n",line_count,yytext);
		}

"for"	{
			fprintf(tokenout,"<FOR>\n");
			fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n\n",line_count,yytext);
		}


"while"	{
			fprintf(tokenout,"<WHILE>\n");
			fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n\n",line_count,yytext);
		}

"do"	{
			fprintf(tokenout,"<DO>\n");
			fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n\n",line_count,yytext);
		}

"break"	{ 	 
			 fprintf(tokenout,"<BREAK>\n");
			 fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n\n",line_count,yytext); }

"int"	{ 		
			fprintf(tokenout,"<INT>\n");
			fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n\n",line_count,yytext);
		}

"char"	{
			fprintf(tokenout,"<CHAR>\n");
			fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n\n",line_count,yytext);
		}

"float"	{
			fprintf(tokenout,"<FLOAT>\n");
			fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n\n",line_count,yytext);
		}

"double" {
			fprintf(tokenout,"<DOUBLE>\n");
			fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n\n",line_count,yytext);	
		}

"void"	{
			fprintf(tokenout,"<VOID>\n");
			fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n\n",line_count,yytext);
		}

"return" {
			fprintf(tokenout,"<RETURN>\n");
			fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n\n",line_count,yytext);
		 }

"switch" {
			fprintf(tokenout,"<SWITCH>\n");
			fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n\n",line_count,yytext);
		 }

"case"	{
			fprintf(tokenout,"<CASE>\n");
			fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n\n",line_count,yytext);
		}

"default"	{
			fprintf(tokenout,"<DEFAULT>\n");
			fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n\n",line_count,yytext);
		}

"continue"	{
			fprintf(tokenout,"<CONTINUE>\n");
			fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n\n",line_count,yytext);
		}

"+"		|
"-"		{
			fprintf(tokenout,"<ADDOP,%s>\n",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n\n",line_count,yytext);
			//table(yytext,"ADDOP");
		}
		
		
{INTIZER_NUMBER} 	{
				fprintf(tokenout,"<CONST_INT,%s>\n",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n\n",line_count,yytext);
				table(yytext,"CONST_INT");
			}

{FLOAT_NUMBER}  {
                    fprintf(tokenout,"<CONST_INT,%s>\n",yytext);
		            fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n\n",line_count,yytext);
		            table(yytext,"CONST_FLOAT");
				             
                }


{CHARACTER_LITERAL}     {
					
					fprintf(tokenout,"<CONST_CHAR,%s>\n",yytext);
					fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n\n",line_count,yytext);
					table(yytext,"CONST_CHAR");


				}

{CHARACTER_LITERAL_EXCEPTION}		{
					
					fprintf(tokenout,"<CONST_CHAR,%s>\n",yytext);
					fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n\n",line_count,yytext);
					table(yytext,"CONST_CHAR");


				}


{IDENTIFIER}  {
							fprintf(tokenout,"<ID,%s>\n",yytext);
							fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\n\n",line_count,yytext);
							table(yytext,"ID");
						}

"*"   |
"/"   |
"%"       {
				fprintf(tokenout,"<MULOP,%s>\n",yytext);
				fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n\n",line_count,yytext);
				//table(yytext,"MULOP");	
		
		  }

"++"  |
"--"       {
				fprintf(tokenout,"<INCOP,%s>\n",yytext);
				fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n\n",line_count,yytext);
				//table(yytext,"INCOP");
		   }

{RELATIONAL_OP}   {
						fprintf(tokenout,"<RELOP,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n\n",line_count,yytext);
					//	table(yytext,"RELOP");		
				  }

"="             {
						fprintf(tokenout,"<ASSIGNOP,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <ASSIGN> Lexeme %s found\n\n",line_count,yytext);
						//table(yytext,"ASSIGNOP");
				}

"&&"  |
"||"             {
						fprintf(tokenout,"<LOGICOP,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <LOGIC> Lexeme %s found\n\n",line_count,yytext);
					   // table(yytext,"LOGICOP");
				  }


"!"             {
						fprintf(tokenout,"<NOT,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n\n",line_count,yytext);
					    //table(yytext,"NOT");		
				  }


"("             {
						fprintf(tokenout,"<LPAREN,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n\n",line_count,yytext);
					//	table(yytext,"LPAREN");
				  }


")"             {
						fprintf(tokenout,"<RPAREN,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n\n",line_count,yytext);
					  //  table(yytext,"RPAREN");		
				  }


"{"             {
						fprintf(tokenout,"<LCURL,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n\n",line_count,yytext);
						//table(yytext,"LCURL");
			}

"}"             {
						fprintf(tokenout,"<RCURL,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n\n",line_count,yytext);
					  //  table(yytext,"RCURL");		
				  }


"["             {
						fprintf(tokenout,"<LTHIRD,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n\n",line_count,yytext);
					   // table(yytext,"LTHIRD");
				  }


"]"             {
						fprintf(tokenout,"<RTHIRD,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n\n",line_count,yytext);
					//	table(yytext,"RTHIRD");
				  }


","             {
						fprintf(tokenout,"<COMMA,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n\n",line_count,yytext);
						//table(yytext,"COMMA");		
				  }


";"             {
						fprintf(tokenout,"<SEMICOLON,%s>\n",yytext);
						fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n\n",line_count,yytext);
					//	table(yytext,"SEMICOLON");
				  }
				  
				  
{SINGLE_LINE_STRING}   {
                            fprintf(tokenout,"<STRING>,%s\n",yytext);
			                fprintf(logout,"Line no %d: TOKEN <STRING> Lexeme %s found\n\n",line_count,yytext);
			                
                           }

\"      { 
			BEGIN STRING_LITERAL;
			fprintf(tokenout,"<STRING>,%s",yytext);
			fprintf(logout,"Line no %d: TOKEN <STRING> Lexeme %s",line_count,yytext);
			
		}                           				  
<STRING_LITERAL>{NEWLINE}     {
			                             line_count++;			
			                             fprintf(logout,"%s",yytext);
			                            // fprintf(tokenout,"%s",yytext);
            }
			

<STRING_LITERAL>\"    {
			fprintf(tokenout,"\">\n");			
			fprintf(logout,"%s found\n\n",yytext);
			BEGIN INITIAL;
			}			

<STRING_LITERAL>.    {
			fprintf(logout,"%s",yytext);
			fprintf(tokenout,"%s",yytext);
			} 				  





{SINGLE_COMMENT}            {
						        fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);
							    //insert in symbol table and print symbol table content(only non empty buckets		
                    
            
                        }


"/*"     {    
                  
                BEGIN(MULTIPLE_LINE_COMMENT);
                line=line_count;
                yy=yy+"/*";
                  
                
         }   
<MULTIPLE_LINE_COMMENT>[^*\n]* {
                                        yy=yy+yytext;
                                            
                               }
                               
<MULTIPLE_LINE_COMMENT>[^*\n]*\n     { 
                                            yy=yy+yytext;
                                            //fprintf(logout,"%s",yytext);                            
                                            line_count++;
                        }
                        
<MULTIPLE_LINE_COMMENT>"*"+[^*/\n]*  {
                                             yy=yy+yytext;
                                             //fprintf(logout,"%s",yytext);

                                      }
        
<MULTIPLE_LINE_COMMENT>"*"+[^*/\n]*\n   {
                                                yy=yy+yytext;
                                                //fprintf(logout,"%s",yytext);                                                    
                                                line_count++;
                           }

<MULTIPLE_LINE_COMMENT>[*]+\/   {   
                                                yy=yy+yytext;
		                                        char a[200];
		                                        strcpy(a,yy.c_str());
		                                        a[sizeof(a) - 1] = 0;
                                                fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line,a);                 
                                                BEGIN(INITIAL);
                    }                                                          

<MULTIPLE_LINE_COMMENT><<EOF>>     {
                                               
                                                char a[200];
		                                        strcpy(a,yy.c_str());
		                                        a[sizeof(a) - 1] = 0;
                                                fprintf(logout,"Error at Line %d: Unterminated comment %s\n\n",line,a);     
                                                error++; 
                                                line_count--;                         
                                                fprintf(logout,"Total lines:%d\n",line_count);
                                                fprintf(logout,"Total errors:%d\n",error);
                                                BEGIN INITIAL;
                                                syt->~SymbolTable();
                                                return 0;
                                      }                 
                                        
                    

                                                                 



{TOO_MANY_DECIMAL_POINT_ERROR}  {
                                      fprintf(logout,"Error at line %d: Too many decimal point %s\n\n",line_count,yytext);  
                                      error++; 


                           }

{ILL_FORMED_NUMBER}  {
                               fprintf(logout,"Error at line %d: Ill formed number %s\n\n",line_count,yytext);
                               error++;    
                     }


{INVALID_SUFFIX_ON_NUMBER_OR_PREFIX_ON_IDENTIFIER}   {
                             fprintf(logout,"Error at line %d: Invalid Suffix on numeBER or invalid prefix on id %s\n\n",line_count,yytext); 
                             error++;   
                            } 
                                
                                
                                
{MULTI_CHAR_ERROR}          {
                                   fprintf(logout,"Error at line %d: Multi character constant error %s\n\n",line_count,yytext); 
                                   error++;   
                            }   
                            
 
{UNFINISHED_CHAR}          {
                                   fprintf(logout,"Error at line %d: Unterminated character %s\n\n",line_count,yytext);  
                                   error++;  
                            }  


{UNRECOGNIZED_CHAR}      {
                                   fprintf(logout,"Error at line %d: Empty character constant error %s\n\n",line_count,yytext);
                                    error++;    
                          }
                         
{UNFINISHED_STR}  {
                                   fprintf(logout,"Error at line %d: Unterminated string %s\n\n",line_count,yytext);
                                   line_count++;
                                    error++;    
                      }

{UNFINISHED_MUL_STR}  {
                                   fprintf(logout,"Error at line %d: Unterminated string %s\n\n",line_count,yytext);
                                   line_count++;
                                   error++;    
                      }    


<<EOF>>     {
                     fprintf(logout,"Total lines:%d\n",line_count);
                     fprintf(logout,"Total errors:%d\n",error);
                     syt->~SymbolTable();
                     return 0;
                     }                                   
 
                             
%%

int main(int argc,char *argv[]){
     
    syt->Enter_scope();
	
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
