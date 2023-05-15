#include<stdio.h> 
#include<stdlib.h> 
struct   process { 

int max[6]; 
int all[6]; 
int  need[6]; 
int finished; 
int request[6];
} p[10]; 


int avail[6] , sseq[6]  , ss =0; 

int check1 =0 , check2  =0; 
int n , pid , nor , nor, work[6] ; 



    int main ()
	{
	
	int  safeseq(void); 
	
	int ch , k , i =0 , j =0 ,  pid , ch1; 
	int violationcheck =0 , waitcheck  =0; 
	do
	{
	
	printf("\n1) input  \n 2) Newrequest  \n 3) safe_safe or not \n 4)print\n 5)exit \n Enter your cchoice \n"); 
	
	scanf("%d", &ch); 
	
	
	
	switch(ch)
	{
	
	case 1:
		printf("enter the number of the processs"); 
		scanf("%d",&n); 
		printf("Enter the number of the resources"); 
		scanf("%d",&nor); 
	
		printf("Enter the number ofhte available resources\n"); 
	
	
	for( j  =0; j<n;j++)
	{
		for(k= 0 ; k < nor ; k++)
		{
		
		if(j==0)
		{
		printf("\n For resouces tpype  %d:", k ); 
		scanf("%d", &avail[k]); 
		
		} 
		
		p[j].max[k] =0; 
		p[j].all[k] = 0; 
		p[j].need[k] =0; 
		p[j].request[k] =0; 
		p[j].finished=0; 
            } 
            
        }
        
        
        
        
        for(i =0; i< n ; i++)
       {
       
       printf("Enterthe max and allklowedresouces for p%d", i ); 
       
       for( j =0 ; j< nor ; j++)
       {
	printf("enter the max of the resouces %d ;",j); 
	
	scanf("%d",&p[i].max[j]); 
	
	printf("\nAllocation of resources%d;", j); 
	scanf("%d", &p[i].all[j]); 
	
	if(p[i].all[j] > p[i].max[j])
	{
		printf("\n  Allocation should be less thena opr eqaul to   max \n"); 
		
		
		j--; 
		
	}
	else 
	   {
	   
	   
	   p[i].need[j] = p[i].max[j] -p[i].all[j]; 
	   
	   
	   }
	   
	   
     } /// number of the resouces  
     
     
     break; 
     
     case 2: 
     		violationcheck =0; 
     		waitcheck=0; 
     		
     		printf("\n Requesting  process ID\n"); 
     		scanf("%d", &pid); 
     		
     		
     		
     		for(j=0 ;j< nor; j++)
     		{
     		
     			printf("\n number of the requesting resources  %d", j); 
     			scanf("%d" , &p[pid].request[j]); 
     			if (p[pid].request[j] > p[pid].need[j])
     				violationcheck =1; 
     			if(p[pid].request[j]> avail[j])
     			         waitcheck=1; 
     		}
     		
     		
     		if(violationcheck==1)
     		
     		printf("The process wexceeeds the maximum limit :\n terminated\n"); 
     		
     		
     		else if(waitcheck ==1)
     		printf("\n laack of the resources:process_state -wait\n"); 
     		
     		else
     		    { 
     		    for(j =0; j<n;j++) 
     		    	{ 
     		    	avail[j ] = avail[j] - p[pid].request[j]; 
     		    	p[pid].all[j] =p[pid].all[j] +p[pid].request[j]; 
     		    	p[pid].need[j] = p[pid].need[j] - p[pid].request[j]; 
     		    	
     		    	} 
     		    	
     		    	ch1 = safeseq(); 
     		    	
     		    	if(ch1 ==0)
     		    	{
     		    		for(j =0 ; j< n ; j++)
     		    		{
     		    			avail[j] = avail[j]+p[pid].request[j]; 
     		    			p[pid].all[j] =p[pid].all[j] - p[pid].request[j]; 
     		    			p[pid].need[j ]  =p[pid].need[j] +p[pid].request[j]; 
     		    		
     		    		}
     		    	
     		    	}
     		    	
     		    	else if(ch1 ==1)
     		    	printf("\nrequest commited\n"); 
     		    	
     		    }  ///  else 
     		    
     		    
     		    break; 
     		    
     case 3 :
     
     		if(safeseq() ==1)
     		printf("\nthe syeztem is in the safe sequence \n"); 
     		else
     		printf("\nthe system is not i nthe sfae sequence\n"); 
     		break ; 
     		
     case 4: 
    		printf("\n number of priocess %d \n",n); 
    		printf("\n NUmber of the resources :%d\n", nor); 
    		
    		printf("\n Pid \t Max\tAllocated \t Need \n"); 
    		
    		for(i = 0 ; i< n; i++)
    		{
    			printf("p%d:", i ); 
    			for(j =0;  j < nor ; j++)
    			printf("%d", p[i].max[j]); 
    			printf("/t"); 
    			
    			for(j = 0 ; j< n ; j++)
    			printf("%d",p[i].all[j]);
    			printf("\t"); 
    			
    			for(j =0; j< nor; j++)
    			printf("%d",p[j].need[j]); 
    			printf("\t"); 
    			
    			
    		} 
    		
    		
    		
    		
    		
    		printf("Available\n"); 
    		for(j =0 ; j< n ; j++)
    		printf("%d",avail[j]); 
    		break; 
    		
    		
   case 5: break; 
   		
   		
    
   
   
   }
   
   } // do 
   
   }
   while(ch != 5);
   return 0;
   
  
  
  }
  
  
 int safeseq()
  {
  		int i , j , k ,tj , tk; 
  		int ss = 0 ; 
  		
  		
  		
  		for (j =0 ; j< nor; j++) 
  		work[j] =  avail[j]; 
  		
  		for(j = 0; j<n ; j++)
  		p[j].finished =0; 
  		for(tk = 0; tk< nor; tk++)
  		{ 
  		    for(j = 0 ; j< n ; j++)
  		    {
  		    
  		    if(p[j].finished ==0)
  		    {
  		       check1 =0; 
  		       
  		       
  		       for( k =0 ; k< n ;k++)
  		       if (p[j].need[k] <= work[k])
  		       check1++;
  		       
  		      if(check1 ==nor)
  		      {
  		      	for(k = 0 ; k< n; k++)
  		      	  { 
  		      	  
  		      	  
  		      	     work[k]  = work[k] + p[j].all[k]; 
  		      	     p[j].finished = 1; 
  		      	     
  		      	     
  		      	  }
  		      	  
  		      	  
  		      	sseq[ss] = j ; 
  		      	ss++; 
  		      	
  		      	
  		      	}    // check for nor 
  		      	
  		      	
  		    }  // check if the processs is finished 
  		 }      // for loop for j 
  		 
  }   // for loop tk 
  
         check2 = 0; 
         
         
         for(i = 0 ; i< n ; i++)
         if(p[i].finished ==1)
         check2++; 
         
         
         printf("\n"); 
         if(check2 >= n)
           { 
           
                for(tj =0; tj < n ; tj++)
                
                printf("p%d",sseq[tj]); 
                
                
                return 1 ;  
            } 
            
            
            
         else
         printf("\n The System is not in safe  state \n"); 
         
         
         return 0; 
         
        }
        
  		
