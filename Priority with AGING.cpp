#include<stdio.h>
#include<stdlib.h>
struct process
{
	char process_name;
	int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
	int status;
}process_queue[100];

int limit;

void Arrival_Time_Sorting()
	{
	struct process temp;
	int i, j;
	for(i=0; i<limit-1; i++)
	{
	  for(j=i+1;j<limit;j++)
	  {
		if(process_queue[i].arrival_time>process_queue[j].arrival_time)
		{
			temp=process_queue[i];
			process_queue[i]=process_queue[j];
			process_queue[j]=temp;
		}
	  }
	}
}

void main()
{
int i,a,time=0, burst_time=0, largest;
char c;
float wait_time=0.0, turnaround_time=0.0, average_waiting_time=0.0, average_turnaround_time=0.0;
printf("*****************AGING TECHNIQUE ALGORITHM***********************");
printf("\n\n NOTE:");
printf("\n As we assumed that CPU is not idle");
printf("\n therefore: \n\t   Atleast one process must have arrival time '0'");
printf("\n\t   Priority must be in natural number");
printf("\n\t   Burst time must be a natural number\n\n");
printf("\nEnter number of processes:");
scanf("%d",&limit);
for(i=0, c='A'; i<limit;i++,c++)
{
 process_queue[i].process_name=c;
printf("\n Enter the details for process[%c]:\n",process_queue[i].process_name);
printf("enter arrival time:");
scanf("%d",&process_queue[i].arrival_time);
if(process_queue[i].arrival_time<0)
	exit(0);
printf("Enter burst time:");
scanf("%d",&process_queue[i].burst_time);
if(process_queue[i].burst_time<=0)
	exit(0);
printf("enter priority:");
scanf("%d",&process_queue[i].priority);
if(process_queue[i].priority<=0)
	exit(0);
//printf("pri %d",&process_queue[i].priority);
process_queue[i].status=0;
burst_time=burst_time+process_queue[i].burst_time;
}
Arrival_Time_Sorting();
process_queue[9].priority=-999;
printf("\n+-----+--------------+------------+----------+");
printf("\n| PID | Arrival Time | Burst Time | Priority |");
printf("\n+-----+--------------+------------+----------+");
//printf("\nprocess name\t Arrival time \tburst time \tpriority\twaiting time");
for(i=0;i<limit;i++)
printf("\n|  %c  |     %2d       |    %2d      |    %2d    |",process_queue[i].process_name,process_queue[i].arrival_time,
		       process_queue[i].burst_time,process_queue[i].priority);
printf("\n+-----+--------------+------------+----------+");
printf("\n\n\n***************Gantt Chart*******************\n\n\n");
for(time=process_queue[0].arrival_time; time<burst_time;)
{
	largest=9;
	for(i=0;i<limit;i++)
	{
		if(process_queue[i].arrival_time<=time&& process_queue[i].status !=1 && process_queue[i].priority>process_queue[largest].priority)
		{
			largest=i;
		}
	}
	time=time+process_queue[largest].burst_time;
	process_queue[largest].ct=time;
	process_queue[largest].waiting_time=process_queue[largest].ct -process_queue[largest].arrival_time-process_queue[largest].burst_time;
	process_queue[largest].burst_time;
	process_queue[largest].turnaround_time=process_queue[largest].ct-process_queue[largest].arrival_time;
	process_queue[largest].status=1;
	wait_time=wait_time+process_queue[largest].waiting_time;
	turnaround_time=turnaround_time+process_queue[largest].turnaround_time;

	//printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",process_queue[largest].process_name,process_queue[largest].arrival_time,process_queue[largest].burst_time, process_queue[largest].priority,process_queue[largest].waiting_time);

   printf(" %d | %c |",process_queue[largest].waiting_time,process_queue[largest].process_name);
   //printf("[%d] ",process_queue[largest].waiting_time);
}

average_waiting_time=wait_time/limit;
average_turnaround_time=turnaround_time/limit;
printf("\n\naverage waiting time:\t%f\n",average_waiting_time);
printf("average turnaround time:\t%f\n",average_turnaround_time);
}

