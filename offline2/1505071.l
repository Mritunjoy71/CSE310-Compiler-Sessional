%option noyywrap
%x STRING_LITERAL
%x MULTIPLE_LINE_COMMENT
%x MULTIPLE_LINE_COMMENT_ERROR
%x SINGLE_LINE_COMMENT

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
int sline=0;
string yy="";
string tt="";

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

TOO_MANY_DECIMAL_POINT_ERROR {DIGIT}*"."{DIGIT}*((".")+{DIGIT}*)+
ILL_FORMED_NUMBER {DIGIT}*(("."{DIGIT}*)*)?([eE][-+]?{DIGIT}*("."{DIGIT}*)+)+
NUMERIC_CONST {DIGIT}*("."{DIGIT}+)?([eE][-+]?{DIGIT}+)?
INVALID_SUFFIX_ON_NUMBER_OR_PREFIX_ON_IDENTIFIER {NUMERIC_CONST}{IDENTIFIER}
MULTI_CHAR_ERROR '..+'
UNFINISHED_CHAR '[A-Za-z0-9]*|'[\\]'
UNRECOGNIZED_CHAR ''




%%

{NEWLINE} {line_count++;}
{WHITESPACE}  {
				
			  }

"if"	{
			fprintf(tokenout,"<IF>");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n\n",line_count,yytext);
		}
		
"else"	{
			fprintf(tokenout,"<ELSE>");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n\n",line_count,yytext);
		}

"for"	{
			fprintf(tokenout,"<FOR>");
			fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n\n",line_count,yytext);
		}


"while"	{
			fprintf(tokenout,"<WHILE>");
			fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n\n",line_count,yytext);
		}

"do"	{
			fprintf(tokenout,"<DO>");
			fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n\n",line_count,yytext);
		}

"break"	{ 	 
			 fprintf(tokenout,"<BREAK>");
			 fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n\n",line_count,yytext); }

"int"	{ 		
			fprintf(tokenout,"<INT>");
			fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n\n",line_count,yytext);
		}

"char"	{
			fprintf(tokenout,"<CHAR>");
			fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n\n",line_count,yytext);
		}

"float"	{
			fprintf(tokenout,"<FLOAT>");
			fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n\n",line_count,yytext);
		}

"double" {
			fprintf(tokenout,"<DOUBLE>");
			fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n\n",line_count,yytext);	
		}

"void"	{
			fprintf(tokenout,"<VOID>");
			fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n\n",line_count,yytext);
		}

"return" {
			fprintf(tokenout,"<RETURN>");
			fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n\n",line_count,yytext);
		 }

"switch" {
			fprintf(tokenout,"<SWITCH>");
			fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n\n",line_count,yytext);
		 }

"case"	{
			fprintf(tokenout,"<CASE>");
			fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n\n",line_count,yytext);
		}

"default"	{
			    fprintf(tokenout,"<DEFAULT>");
			    fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n\n",line_count,yytext);
		    }

"continue"	{
	            fprintf(tokenout,"<CONTINUE>");
	            fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n\n",line_count,yytext);
		    }

"+"		|
"-"		{
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n\n",line_count,yytext);
			//table(yytext,"ADDOP");
		}
		
		
{INTIZER_NUMBER} 	{
				fprintf(tokenout,"<CONST_INT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n\n",line_count,yytext);
				table(yytext,"CONST_INT");
			}

{FLOAT_NUMBER}  {
                    fprintf(tokenout,"<CONST_INT,%s>",yytext);
		            fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n\n",line_count,yytext);
		            table(yytext,"CONST_FLOAT");
				             
                }


{CHARACTER_LITERAL}     {
					            char ch=yytext[1];
					            fprintf(tokenout,"<CONST_CHAR,%c>",ch);
					            fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n\n",line_count,yytext);
					            table(yytext,"CHAR_CONST");
				}

{CHARACTER_LITERAL_EXCEPTION}  {
					                    fprintf(tokenout,"<CONST_CHAR,    >");
					                    fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n\n",line_count,yytext);
					                    table(yytext,"CHAR_CONST");
				                }


{IDENTIFIER}  {
							fprintf(tokenout,"<ID,%s>",yytext);
							fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\n\n",line_count,yytext);
							table(yytext,"ID");
						}

"*"   |
"/"   |
"%"       {
				fprintf(tokenout,"<MULOP,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n\n",line_count,yytext);
			
		
		  }

"++"  |
"--"       {
				fprintf(tokenout,"<INCOP,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n\n",line_count,yytext);
				
		   }

{RELATIONAL_OP}   {
						fprintf(tokenout,"<RELOP,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n\n",line_count,yytext);
							
				  }

"="             {
						fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <ASSIGN> Lexeme %s found\n\n",line_count,yytext);
						
				}

"&&"  |
"||"             {
						fprintf(tokenout,"<LOGICOP,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <LOGIC> Lexeme %s found\n\n",line_count,yytext);
					  
				  }


"!"             {
						fprintf(tokenout,"<NOT,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n\n",line_count,yytext);
					   	
				  }


"("             {
						fprintf(tokenout,"<LPAREN,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n\n",line_count,yytext);
					
				  }


")"             {
						fprintf(tokenout,"<RPAREN,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n\n",line_count,yytext);
					
				  }


"{"             {
						fprintf(tokenout,"<LCURL,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n\n",line_count,yytext);
			   }
			

"}"             {
						fprintf(tokenout,"<RCURL,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n\n",line_count,yytext);		
				  }


"["             {
						fprintf(tokenout,"<LTHIRD,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n\n",line_count,yytext);
				  }


"]"             {
						fprintf(tokenout,"<RTHIRD,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n\n",line_count,yytext);
				 }


","             {
						fprintf(tokenout,"<COMMA,%s>",yytext);
						fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n\n",line_count,yytext);		
				 }


";"  {
		fprintf(tokenout,"<SEMICOLON,%s>",yytext);
		fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n\n",line_count,yytext);
	 }
				  
				  


\"      { 
			BEGIN STRING_LITERAL;
			yy="";
			tt="";
			sline=line_count;
            yy=yy+yytext;
            tt=tt+yytext;			
		} 
		                          				  
<STRING_LITERAL>{NEWLINE}     {
	                                 line_count++;
	                                 char a[500];
                                     strcpy(a,yy.c_str());
                                     a[sizeof(a) - 1] = 0;	
	                                 fprintf(logout,"Error at line %d: unterminated string %s\n\n",sline,a);
	                                 yy="";
	                                 tt="";
	                                 error++;
                                     BEGIN INITIAL;					                            
                                }
			

<STRING_LITERAL>\"        {
                                    yy=yy+yytext;
                                    tt=tt+yytext;
                                    char a[500];
                                    strcpy(a,yy.c_str());
                                    a[sizeof(a) - 1] = 0;
                                    char b[500];
                                    strcpy(b,tt.c_str());
                                    b[sizeof(b) - 1] = 0;
			                        fprintf(tokenout,"<STRING,%s>",b);			
			                        fprintf(logout,"Line no %d: TOKEN <STRING> Lexeme %s found\n\n",sline,a);
			                        yy="";
			                        tt="";
			                        BEGIN INITIAL;
			               }	
					
<STRING_LITERAL>[^\"\n\\]+     {
                                        yy=yy+yytext;
			                            tt=tt+yytext;
			                     }

<STRING_LITERAL>[^\"\n\\]*\\\n  {
                                        yy=yy+yytext;
                                        string t;
                                        t=yytext; 
			                            int n=t.size();
			                            for(int i=0;i<n-2;i++)
			                            {   
			                                tt=tt+t[i];
			                            }
			                            line_count++;



                                }	
                                		         
<STRING_LITERAL>[^\"\n\\]+\n   {
			                        yy=yy+yytext;
                                    line_count++;
                                    char a[500];
                                    strcpy(a,yy.c_str());
                                    a[sizeof(a) - 1] = 0;		
		                            fprintf(logout,"Error at line %d: unterminated string %s\n\n",sline,a);
		                            yy="";
		                            tt="";
		                            error++;
		                            BEGIN INITIAL;
			         } 		
			         
<STRING_LITERAL>\\t  {
                            yy=yy+yytext;
			                tt=tt+"    ";                       
                    }			         	          				  

"//"             {
					       fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s",line_count,yytext);
					       BEGIN SINGLE_LINE_COMMENT;
							    
                     }
                  
<SINGLE_LINE_COMMENT>[^\n\/]+[\\]\n    {
					                    fprintf(logout,"%s",yytext);
					                    line_count++;
				                  } 
                  
<SINGLE_LINE_COMMENT>[^\n\\]*    {
					                    fprintf(logout,"%s",yytext);
					                   
				                  }

<SINGLE_LINE_COMMENT>\n   {
					                    fprintf(logout," found\n\n");
					                    line_count++;
					                    BEGIN INITIAL;
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
                                    char a[500];
                                    strcpy(a,yy.c_str());
                                    a[sizeof(a) - 1] = 0;
                                    fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line,a);                 
                                    BEGIN(INITIAL);
                    }                                                          

<MULTIPLE_LINE_COMMENT><<EOF>>     {
                                               
                                                char a[500];
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
                           

<<EOF>>     {
                     fprintf(logout,"Total lines:%d\n",--line_count);
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