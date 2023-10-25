%{
#include<math.h>
#include"y.tab.h"
#include"parser.h"
%}

ID [A-Za-z][A-Za-z0-9]*

%%
[0-9]+   {
            yylval.intval=atoi(yytext);
            return NUMBER;
        }

[ \t]   ;

{ID}    {
            yylval.symp=symlook(yytext);
            return NAME;
        }

"$"     {
            return 0;
        }

\n|.    return yytext[0];
%%

int yywrap(void)
{
    return 1;
}