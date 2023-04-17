%{
#include <stdio.h>
#include <string.h>
void yyfail();
int noperands=0,noperators=0;
char operands[10][10],operators[10][10];
int valid=0;
%}
%%
"(" valid++;
")" {valid--;
if(valid<0) fail();}
"+"|"*" {strcpy(operators[noperators],yytext);
noperators++;}
[0-9]+ {strcpy(operands[noperands],yytext);
noperands++;}
[^+*]"("[^0-9] fail();
[+*]")" fail();
%%
int main()
{
int i=0;
printf("Enter a mathematical expression and press \n");
yylex();
printf("no ofoperators are: %d\n no of operands are: %d\n",noperators, noperands);
if(valid==0 && noperands-noperators==1)
{
	printf("Expression is valid\n");
	printf("the operands are : \n");
	for(i=0;i<noperands;i++)
		printf("%s\n",operands[i]);
		printf("The operators are : \n");
		for(i=0; i<noperators; i++)
		printf("%s\n",operators[i]);
}
else
{
	printf("Invalid Expression\n");
}
return 0;
}
void yyfail()

{
printf("invalid\n");
exit(0);
}
