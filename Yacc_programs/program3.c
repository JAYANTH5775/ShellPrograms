#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,i,j,k,count;
char grm[10][20], fst[10][20], fol[10][20], tble[3][4], inp[20], inpt[20],mch[20], stk[20];
void firstSet();
void followSet();
void parsingTable();
void parseInput();
void print(char* s);
void main() {
	setbuf(stdout,NULL);
	printf("The Given Grammar is : \n");
	
	
	printf("A->aBa\nB-bB|@\n");
	printf("Enter The Number Of Rules : ");
	scanf("%d", &n);
	
	printf("Enter The Rules : \n");
	for (i = 0; i < n; i++)
	scanf("%s", grm[i]);


	firstSet();
	followSet();
	parsingTable();
	parseInput();
}
void firstSet() {
	printf("The First Set Is : \n");
	for (i = 0; i < n; i++) {
		count = 0;
		j = 3;
		
	printf("FIRST[%c]={", grm[i][0]);
		
		while (grm[i][j] != '\0') 
		{
			if (!(grm[i][j] >= 65 && grm[i][j] <= 90))
			{
				fst[i][count++] = grm[i][j];
				printf("%c,", grm[i][j]);
			}
		while (grm[i][j] != '|' && grm[i][j] != '\0')
			j++;
		j++;
		} //outer while loop
	printf("\b}\n");
	}
}
void followSet() {
	printf("The Follow Set Is : \n");
	for (k = 0; k < n; k++) 
	{
		count = 0;
		printf("FOLLOW[%c]={", grm[k][0]);
			if (k == 0) 
			{
			printf("$,");
			fol[k][count++] = '$';
			}
		for (i = 0; i < n; i++) 
		{
			for (j = 3; grm[i][j] != '\0'; j++) 
			{
		if (grm[i][j] == grm[k][0] && grm[i][j + 1] != '\0'&& grm[i][j + 1] != '|')
		 {
		
			if (!(grm[i][j + 1] >= 65 && grm[i][j + 1] <= 90))
			{
				printf("%c,", grm[i][j + 1]);
				fol[k][count++] = grm[i][j + 1];
			}
		  }
		} // for loop j 
	} // for loop i 
printf("\b}\n");
     }  // for loop k 
}
	void parsingTable() 
	{
		char p[10], q[10], r[10], f;
		strcpy(p, "A->aBa");
		strcpy(q, "B->bB");
		strcpy(r, "B->@");
		tble[1][0] = 'A';
		tble[2][0] = 'B';
		tble[0][1] = 'a';
		tble[0][2] = 'b';
		tble[0][3] = '$';
	for (i = 0; i < n; i++) 
	{
	for (j = 0; fst[i][j] != '\0'; j++)
	 {
		f = fst[i][j];
		
		if (f == 'a')
		tble[i + 1][1] = 'p';
		
		else if (f == 'b')
		tble[i + 1][2] = 'q';
		
		else if (f == '@') 
		{
		for (k = 0; fol[i][k] != '\0'; k++)
		if (fol[i][k] == 'a')
		tble[i + 1][1] = 'r';
		}
	}   // for j 
     }    // for i 
	
	
	
	printf("The Parsing Table is : \n");
	for (i = 0; i < 3; i++) 
	{
		for (j = 0; j < 4; j++) 
		{
		if (tble[i][j] == 'p')
		
		printf("%s\t\t", p);
		
		else if (tble[i][j] == 'q')
		printf("%s\t\t", q);
		
		else if (tble[i][j] == 'r')
		printf("%s\t\t", r);
		else
		printf("%c\t\t", tble[i][j]);
		}
	printf("\n");
	} /// for i 
}
void parseInput() {
	printf("Enter The String : ");
	scanf("%s", inp);
	strcpy(inpt, inp);
	strcat(inpt, "$");
	strcpy(stk, "A$");
	i = 0;
	j = 0;
	k = 0;
	printf("Matched\t\tStack\t\tInput\t\tActio\n");
		while (1)
		 {
			if (stk[i] == inpt[j])
			 {
				if (stk[i] == '$')
				{
				print("Accepted\n");
				break;
			        }
			print("POP");
			printf(" %c\n", stk[i]);
			mch[k++] = stk[i];
			stk[i++] = inpt[j++] = ' ';
			continue;
			} 
			else if (stk[i] == 'A') 
			{
				print("A->aBa\n");
				strcpy(stk, "aBa$");
			} 
			else if (stk[i] == 'B' && inpt[j] == 'b')
			 {
				print("B->bB\n");
				strcpy(stk, "bBa$");
			i = 0;
			} 
			else if (stk[i] == 'B' && inpt[j] == 'a') 
			{
				("B->@\n");
				stk[i++] = ' ';
			} 
			else 
			{
			print("ERROR\n");
			exit(0);
		       }
	}
	}


void print(char* s) 
{
     printf("%s\t\t%s\t\t%s\t\t%s", mch, stk, inpt, s);
}

