%{ 

#include<stdio.h> 

#include "y.tab.h" 

%} 


%% 
int|char|bool|float|void|for|do|while|if|else|return|void|main {  printf("the keyword is %s \n ",yytext); return KEY ; } 
[+|-|*|/|=|<|>] {printf("operators are     is %s  \n", yytext );  return OP; }
[a-zA-z][a-zA-Z0-9]  {printf("identifier is %s\n", yytext ); return ID; } 





. ; 


