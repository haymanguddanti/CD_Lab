%{
    #include<stdio.h>
%}
%%
if|else|while|switch|for|char   {printf("keyword");}
[a-zA-Z]*([a-zA-Z][0-9])*       {printf("identifier");}
.*                              {printf("Invalid");}
%%
int main()
{
    yylex();
    return 0;
}
int yywrap()
{
}   