%{
	int cc=0,wc=0,lc=0,sc=0;
%}
%%
[\n]+ {lc++; wc++;}
[\t] {sc++; wc++;}
[" "] {sc++;}
[^\n\t] {cc++;}
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
	printf("total number of lines %d\n",lc);
	printf("total number of word %d\n",wc);
	printf("total number of character %d\n",cc);
	printf("total number of space %d\n",sc);
}
