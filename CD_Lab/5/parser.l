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
