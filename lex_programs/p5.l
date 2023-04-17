%%
"rama" {fprintf(yyout,"RAMA");}
"sita" {fprintf(yyout,"SITA");}
%%
int main(int argc,char** argv)
{
	yyin=fopen(argv[1],"r");
	yyout=fopen(argv[2],"w");
	yylex();
}
