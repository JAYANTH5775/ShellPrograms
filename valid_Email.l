%{
int flag=0; 




%}

%%

[a-zA-Z0-9]+"@"[a-z]+".com"|".in" {flag=1;}
.;

%%


void main()

 {
 yylex(); 
 if (flag==1)
 {

 printf("valid Email]\n"); 
 }
 else
 {
 printf("invalid email\n"); 



 }
 
 
 }


