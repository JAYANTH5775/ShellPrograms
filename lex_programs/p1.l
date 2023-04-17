%{
int nv=0,nc=0;
%}
%%
[aeiouAEIOU] {nv++;}
[a-zA-Z]  {nc++;}
%%
int main()
{
yylex();
printf("number of vowels=%d\n",nv);
printf("number of consonents=%d\n",nc);
}

