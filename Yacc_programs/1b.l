
%{
#include "y.tab.h"
#include <stdlib.h>
extern int yylval;
%}
%%
[0-9]+ {yylval=atoi(yytext);
	return NUM;}
\n  {return 0;}
.  {return yytext[0];}
%%
