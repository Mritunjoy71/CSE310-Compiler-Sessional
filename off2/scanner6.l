Line no 1: TOKEN <INT> Lexeme int found

Line no 1: TOKEN <ID> Lexeme main found

ScopeTable #1
0 --><main,ID>    
Line no 1: TOKEN <LPAREN> Lexeme ( found

Line no 1: TOKEN <RPAREN> Lexeme ) found

Line no 1: TOKEN <LCURL> Lexeme { found

Line no 2: TOKEN <INT> Lexeme int found

Line no 2: TOKEN <ID> Lexeme a found

ScopeTable #1
0 --><main,ID>    
6 --><a,ID>    
Line no 2: TOKEN <COMMA> Lexeme , found

Line no 2: TOKEN <ID> Lexeme b found

ScopeTable #1
0 --><main,ID>    <b,ID>    
6 --><a,ID>    
Line no 2: TOKEN <SEMICOLON> Lexeme ; found

Line no 3: TOKEN <ID> Lexeme a found

Line no 3: TOKEN <ASSIGN> Lexeme = found

Line no 3: TOKEN <ID> Lexeme a found

Line no 3: TOKEN <ADDOP> Lexeme + found

Line no 3: TOKEN <CONST_INT> Lexeme 1 found

ScopeTable #1
0 --><main,ID>    <b,ID>    <1,CONST_INT>    
6 --><a,ID>    
Line no 3: TOKEN <SEMICOLON> Lexeme ; found

Line no 4: TOKEN <CHAR> Lexeme char found

Line no 4: TOKEN <ID> Lexeme ch found

ScopeTable #1
0 --><main,ID>    <b,ID>    <1,CONST_INT>    
3 --><ch,ID>    
6 --><a,ID>    
Line no 4: TOKEN <ASSIGN> Lexeme = found

Line no 4: TOKEN <CONST_CHAR> Lexeme 'a' found

ScopeTable #1
0 --><main,ID>    <b,ID>    <1,CONST_INT>    
1 --><'a',CHAR_CONST>    
3 --><ch,ID>    
6 --><a,ID>    
Line no 4: TOKEN <SEMICOLON> Lexeme ; found

Line no 5: TOKEN <ID> Lexeme ch found

Line no 5: TOKEN <ASSIGN> Lexeme = found

Line no 5: TOKEN <CONST_CHAR> Lexeme '\t' found

ScopeTable #1
0 --><main,ID>    <b,ID>    <1,CONST_INT>    
1 --><'a',CHAR_CONST>    
3 --><ch,ID>    
5 --><'\t',CHAR_CONST>    
6 --><a,ID>    
Line no 5: TOKEN <SEMICOLON> Lexeme ; found

Line no 6: TOKEN <CHAR> Lexeme char found

Line no 6: TOKEN <ID> Lexeme c found

ScopeTable #1
0 --><main,ID>    <b,ID>    <1,CONST_INT>    
1 --><'a',CHAR_CONST>    <c,ID>    
3 --><ch,ID>    
5 --><'\t',CHAR_CONST>    
6 --><a,ID>    
Line no 6: TOKEN <LTHIRD> Lexeme [ found

Line no 6: TOKEN <RTHIRD> Lexeme ] found

Line no 6: TOKEN <ASSIGN> Lexeme = found

Line no 6: TOKEN <STRING> Lexeme "ab\td" found

Line no 6: TOKEN <SEMICOLON> Lexeme ; found

Line no 7: TOKEN <ID> Lexeme printf found

ScopeTable #1
0 --><main,ID>    <b,ID>    <1,CONST_INT>    
1 --><'a',CHAR_CONST>    <c,ID>    
3 --><ch,ID>    <printf,ID>    
5 --><'\t',CHAR_CONST>    
6 --><a,ID>    
Line no 7: TOKEN <LPAREN> Lexeme ( found

Line no 7: TOKEN <STRING> Lexeme "abc\
def\
ghi" found

Line no 9: TOKEN <RPAREN> Lexeme ) found

Line no 9: TOKEN <SEMICOLON> Lexeme ; found

Line no 10: TOKEN <COMMENT> Lexeme // a comment found

Line no 11: TOKEN <COMMENT> Lexeme /** another
*** comment ***/ found

Line no 13: TOKEN <RETURN> Lexeme return found

Line no 13: TOKEN <CONST_INT> Lexeme 0 found

ScopeTable #1
0 --><main,ID>    <b,ID>    <1,CONST_INT>    
1 --><'a',CHAR_CONST>    <c,ID>    
3 --><ch,ID>    <printf,ID>    
5 --><'\t',CHAR_CONST>    
6 --><a,ID>    <0,CONST_INT>    
Line no 13: TOKEN <SEMICOLON> Lexeme ; found

Line no 14: TOKEN <RCURL> Lexeme } found

Total lines:15
Total errors:0