%{

#include<stdio.h> 

%}


%%

[\t]+ ;
"Monday"|"Tuesday"|"Wdnesday"|"Thursday"|"Friday"|"saturday"|"sunday" {

printf("%s\n is a day",yytext);

}

[a-zA-Z]+  {
printf("%s is not a day\n",yytext);
}

 {
 printf("invalid input"); 
 }

%%


void main()
{
 printf("enter the text\n"); 
 yylex(); 

}

