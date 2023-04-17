%{
int nv=0,nc=0;
%}
%%
[aeiouAEIOU] {nv++;}
[a-zA-Z] {nc++;}
%%
int main(int argc,char** argv)
{
	if(argc!=5)
	{
		("error");
		exit(0);
	}
	yyin=fopen(argv[1],"r");
	yylex();
	printf("number of vowels=%d\n",nv);
	printf("number of consonents=%d\n",nc);
}
