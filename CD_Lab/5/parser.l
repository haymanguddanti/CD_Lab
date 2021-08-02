%{
#include<stdio.h>
#include "parser.tab.h"
%}
%%
[0-9]+ {yylval.dval=atof(yytext);
return DIGIT;
}
\n|. return yytext[0];
%%
int yywrap()
{
}

/*
Execution:
flex parser.l
yacc -d parser.y
gcc lex.yy.c parser.tab.c -lm
*/
