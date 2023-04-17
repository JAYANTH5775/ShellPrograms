%{
	int id=0, nid=0;
%}
%%
[a-zA-Z][a-zA-Z_0-9]* {id++;}
[0-9][a-zA-Z_0-9]* {nid++;}
%%
int main(int argc,char** argv)
{
	if(argc!=2)
	{
		printf("error");
		exit(0);
	}
	yyin=fopen(argv[1],"r");
	yylex();
	printf("identfier are=%d\n",id);
	printf("non-identifier are=%d\n",nid);
}
