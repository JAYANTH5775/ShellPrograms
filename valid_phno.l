%{

#include<stdio.h> 





%}




%%

[\n] {printf("enter the mobile number\n"); }
[1-9][0-9]{9} {printf("the movile number is valid\n"); }
.* {printf("mobile number is invalid\n"); }


%%




int main()
{
printf("enter the mobile number \n."); 
yylex(); 
return 0;
} 



