#include<stdio.h> 
#include<stdlib.h>
int no ; 

void roundrobin(int , int, int[], int[]); 



void srtf(); 


int  main ()
	{





	int n, tq, choice ; 

	int bt[10] , st[10] , i, j,k; 


	for (;;)

	{
	
	printf("Enter you r choice\n"); 
	printf("1) round robin \n    2) Shortest time first \n 3)exit \n"); 
	scanf("%d", &choice); 
	
	switch(choice)
	{
	
	case 1: 
	
		printf("Round Robin  scheduling algorithm\n"); 
		printf("enter the numebr of the process");
		scanf("%d", &n); 
		 
	
	        printf("enter burst time of the sequences \n"); 
	
	
	
		for(i=0; i<n;i++)
		{

		scanf("%d", &bt[i]); 
		st[i] = bt[i]; 
		
	}
	
	
		printf("enter the  time quantum\n"); 
	
	
		scanf("%d", &tq); 
	
	
		roundrobin(n,tq, st, bt); 
	
	
		break ; 
	case 2: 
		printf("---------------shortest time fisrst ----------\n\n\n"); 
		srtf(); 
		break ; 
	case 3: exit(0); 
		break ; 
		
	} // switch 
	
	
	}  // loop 
	
} //main 





void roundrobin(int n , int tq , int  st[] , int bt[])

	{
	
	int time =0 ,tat[10] , wt [10] , count =0 , swt =0, stat =0; 
	
	
	int temp ,sq =0 ,i , k; 
	float awt =0.0 , atat =0.0; 
	
	
	while(1)
	
	{
	
	
	
	for (i =0 ,count =0 ; i<n  ; i++)
	{
		temp= tq ; 
		
		if (st[i] ==0)
		{
		count++; 
		continue; 
		}
		
		if (st[i] > tq)
			st[i] = st[i]-tq; 
		
		else if (st[i]>=0)
		{
		temp = st[i];
		st[i] =0;
		}
	
		sq = sq +temp; 
		tat[i] = sq; 
	}
	 ///for loop 

	if (n == count)
	break ; 
	
	}
	
	
	for (i =0; i< n; i++)
	{
	
	
	
	wt[i] = tat[i] - bt[i]; 
	
	swt = swt+wt[i]; 
	stat = stat+tat[i]; 
	
	}
	
	
	
	awt = (float)swt/n ; 
	atat = (float)stat/n;
	
	printf("process no of the burst time   waiting ttime    turn around time \n"); 
	
	for(i  =0; i< n ; i++)
	printf("%d\t\t %d\t\t %d\t\t %d\t\t\n", i+1,bt[i], wt[i], tat[i]); 
	
	
	
	printf("the avaearge waiting time in  %f  \n avearagea turn around time is %f   \n ", awt, atat);
	
	
	
	
	
	}
	
	
	
void  srtf() 

{



	int n , j =0 ,st[10], bt [10], rt[10], remain=0; 
	int smallest , time =0 , i , endtime , swt=0 , stat =0 ; 
	
	
	printf("enter the number of the process"); 
	scanf("%d",&n); 
	
	
	
	for (i =0; i< n;i++)
	{
		printf("enter the arrival time for  p[%d]: ",i+1); 
		scanf("%d" , &st[i]); 
		printf("enter the burst time  for p[%d]:",i+1); 
		scanf("%d", &bt[i]); 
		}
	
	rt [100] = 999; 
	printf("the process \twaiting time\tturn around time\n"); 
	for(time =0; remain !=n ; time++)
	{
	smallest =100; 
	for(i =0 ; i<n;i++)
		{
		if(st[i]<=time  && rt[i] < rt[smallest]  && rt[i] > 0)
			{
			smallest =i; 
			}
	}
		rt[smallest]--; 
		if(rt[smallest] ==0)
		
		{
		remain++; 
		endtime = time +1; 
		j = smallest; 
		
		
		
		printf("p[%d]\t| \t%d\t |\t %d\t\n",smallest+1, endtime-bt[j]-st[j], endtime-st[j]); 
		
		swt+=endtime-bt[j] -st[j]; 
		stat +=endtime-st[j]; 
		
		}
	}
	
	
	
	
	
	float awt =0.0 ,atat =0.0; 
	awt = (float)swt/n; 
	atat = (float)stat/n; 
	printf("Average  waaiting time %f\n", awt); 
	printf("Average turn around time %f\n", atat); 
	
	
	}
	
	
	 
	
	
	


