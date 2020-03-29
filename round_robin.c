#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int rearrange_process_queue(int pq[],int n,int running_processes)
{
    int i;
    int a=pq[0];
    for(i=0;i<running_processes;i++)
    {
        pq[i]=pq[i+1];
    }
    pq[running_processes-1]=a;
}
float avg_turnaround_time(int tat[], int n)
{
    float x=0;
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+tat[i];
    }
    x=sum*1.0;
    x=x/n;
    return x;
}

float avg_wait_time(int wt[], int n)
{
    float x=0;
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+wt[i];
    }
	x=sum*1.0;
    x=x/n;
    return x;
}


 int  queue(int n)
  {
  int arr_time[20],burst_time[20],remain_time[20];
  char process[20];
  int time_quantum,time,i,j;
  printf("enter the fixed time to be spent on queries:-");
  scanf("%d" ,&time_quantum);
 
  printf("--------------------------------------------------\n");
  printf("|\tPROCESS\t|\tAT\t|\tBT\t|\n");
  for(i=0;i<n;i++)
  {
  	  scanf(" %c",&process[i]);
      scanf("%d\t%d",&arr_time[i],&burst_time[i]);
      printf("|\t%c\t|\t%d\t|\t%d\t|\n",process[i],arr_time[i],burst_time[i]);
      remain_time[i]=burst_time[i];
      
  }
 
  int pq[20],pflag[20],tat[20],wt[20];
  
  for(j=0;j<n;j++)
    {
        pq[j] = 0;
        pflag[j] = 0;

    }


  int running_processes=0;
    pq[0]=1;
    running_processes=1;
    pflag[0]=1;
    int flag=0;
    while(running_processes!=0)
        {
        flag=0; 
        printf("Process queue: ");
        for(i=0;i<running_processes;i++)
        {
            printf("%c ",process[pq[i]-1]);
        }
        printf("\t");
        printf("Remaining Time: ");
        for(i=0;i<n;i++)
        {
		
            printf("%d ",remain_time[i]);
        }
        printf("\tRunning processes: %d\n",running_processes);

        if(remain_time[pq[0]-1]>time_quantum)
        {
            remain_time[pq[0]-1]=remain_time[pq[0]-1]-time_quantum;
            time=time+time_quantum;
            printf("Process %d executed for %d runs till time %d\n",pq[0],time_quantum,time);
            
        }
       
        else
        {
            time=time+remain_time[pq[0]-1];
            printf("Process %d executed for %d runs till time %d\n",pq[0],remain_time[pq[0]-1],time);
            remain_time[pq[0]-1]=0;
            flag=1;
        
            tat[pq[0]-1]=time-arr_time[pq[0]-1];
            wt[pq[0]-1]=tat[pq[0]-1]-burst_time[pq[0]-1];
        }

        for(i=0;i<n;i++)
        {
            if(arr_time[i]<=time && pflag[i]== 0)
            {
                pq[running_processes]=i+1;
                running_processes=running_processes+1;
                pflag[i]=1;
            }
        }

        rearrange_process_queue(pq,n,running_processes);
        if(flag==1)
        {

            running_processes=running_processes-1;
        }
        if(time>=120)
        {
        	break;
		}
}
printf("\n\n Details of the Sudesh that he spent :\n");
   
   printf("|\tProcess\t|\tAT\t|\tBT\t|\tTAT(spent)\t|\tWT\t|\n");
   for(i=0;i<n;i++)
   {
       printf("|\t%c\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",process[i],arr_time[i],burst_time[i],tat[i],wt[i]);
   }

printf("\n\nAverage Waiting Time= %f\n",avg_wait_time(wt,n));
  printf("Avg (query) Turnaround Time = %f\n",avg_turnaround_time(tat,n));
return 0;
}




int main()
{
   int i,j,n; 
   int time_quantum;
   int time = 0,select_queue; 
   printf("Please choose a queue to post your query : ");
   printf("\n1. FACULTY queue.");
   printf("\n2. STUDENT queue.");
   scanf("%d", &select_queue);
   printf("selected queue is",select_queue);
  printf("\t--------------------------------------------------\n");
  printf("\t\t BY ROUND ROBIN SCHEDULING ALGORITHM\n");
  printf("\t--------------------------------------------------\n");
 switch(select_queue)
 {
 	
 	case 1 :
	 	
        printf("Enter number of process or queries for FACULTY queue : ");
    	scanf("%d", &n);
    			       
        queue(n);
                
        break;
        
	case 2 :
		
        printf("Enter number of process or quries for STUDENT queue : ");
    	scanf("%d", &n);
    			
               
        queue(n);
                
        break;

        default : 
        
        printf("Please selet the correct option by running the program again.");
    }
  }
