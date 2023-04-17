%{

int flag =0;

%} 


%%

[aA][nN][dD] {flag =1;}
[bB][uU][tT] { flag =1; } 

[bB][eE][cC][aA][uU][sS][eE] {flag =1;}


%%



void main()

{

printf("ENTER THE SENTENCE\n"); 
yylex(); 


if(flag ==0)
printf("sentence is simple "); 


else
printf("snetence is copmpund"); 




}




