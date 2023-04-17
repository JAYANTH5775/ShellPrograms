%{
#include<stdio.h> 
#include<string.h> 
int valid =0 , nooper =0, noopen = 0, i =0,j=0; 
char oper[10][10] , operand[10][10]; 
int YYFAIL(); 
%}

%%
"(" {valid =1;} 
")" {valid = 0;}
"+"|"*" { nooper++; strcpy(oper[i],yytext); i++;}
[0-9]+ {noopen++ ; strcpy(operand[j] ,yytext); j++;}
[^+-]"("[^0-9] YYFAIL();


%%
int main()
{
int k =0; 
printf("enter the exp"); 
yylex(); 
	if ( valid ==0 &&(noopen-nooper) ==1)
	{
	printf("the exp is valid\n"); 
	
	
	printf("the number of the operand is :\n"); 
	
	for ( k =0; k<=i;k++)
	printf("%s\n", operand[k]); 
 	printf("the number of operator is :\n"); 
 	
 	for (k=0; k<=j;k++)
 	printf("%s\n",oper[k]); 
	}	

    else 
	{
	
		printf("invalid exp\n"); 
		return 0 ; 
	
	}

}


int YYFAIL()
{

printf("the invalid\n "); 
exit(0); 

}


