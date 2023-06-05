%{
#include<stdio.h>
#include<stdlib.h> 

int id = 0, key =0 , op =0 ; 


%} 

%token KEY  OP ID 

%% 


input : ID input { id++; }
|KEY  input{key ++; } 
|OP input{op++; } 
|ID {id++; }
| KEY {key++; } 
| OP {op++; }

%% 

extern FILE *yyin; 


void main (int argc , char **argv ) 
{

    yyin  = fopen(argv[1], "r"); 
    yyparse();
   
    printf("keywords = %d \n Identifier %d\n  operators %d\n" , key,id,  op ); 
    } 
    
    void yyerror()
    {
    printf("npt valid"); 
    exit(0); 
    }
