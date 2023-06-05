%{ 

#include <stdio.h> 

int acount = 0, n ; 




%} 




%token A
%token B   

%%

s: X B { if(acount< n || acount >n)
  {

 YYFAIL(); 
 
 }
 
} 

X : X T | T 
T : A {acount++; } 

; 

%% 


int main()
  {  
  
  printf("Enter the vlaue of the of n \n"); 
  
  scanf("%d" , &n); 
  
  printf("enter the string \n"); 
  
  yyparse(); 
  
  printf("valid string \n"); 
  
  } 
  
  
  
int YYFAIL()

   { 
   
   printf("invlaid count of a \n"); 
   
   exit(0); 
   
   } 
   
   int yyerror()
   
   {
   
   printf("invalid string"); 
   
   exit(0); 
   
   }
 
