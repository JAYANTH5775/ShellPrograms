%{
#include<stdio.h>
#include<string.h>
int nooper=0,nooperand=0,i=0,j=0,valid=0;
char opnd[10][10],opert[10][10];
int YYFAIL();
%}
%%
"(" {valid=1;}
")" {valid=0;}
"-" {valid=2;}
"+"|"*" {nooper++; strcpy(opert[i],yytext);i++;}
[0-9]+ {nooperand++; strcpy(opnd[j],yytext);j++;}
[^+*]"("[^0-9] YYFAIL();
%%
int main()
{
	int k;
	printf("Enter the expression\n");
	yylex();
	if(valid==0 && (nooperand-nooper)==1)
	{
		printf("The expression is valid\n");
		printf("The operartors are\n");
		for(k=0;k<i;k++)
		printf("%s\n",opert[k]);
		printf("The operands are\n");
		for(k=0;k<j;k++)
		printf("%s\n",opnd[k]);
	}
	else
	{
		printf("The expression is invalid");
		return 0;
	}
}
int YYFAIL()
{
	printf("Inavild");
	exit(0);
}
