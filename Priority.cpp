#include<stdio.h>
#include<stdlib.h>

typedef struct process1{
	char name1[5];
	int bt1;
	int at1;

	int prt1;
	int wt1,ta1;
	int flag1;
}processes1;


void b_sort1(processes1 temp1[],int n1)
{
	processes1 t1;
	int i1,j1;
	for(i1=1;i1<n1;i1++)
		for(j1=0;j1<n1-i1;j1++){
			if(temp1[j1].at1 > temp1[j1+1].at1){
				t1 = temp1[j1];
				temp1[j1] = temp1[j1+1];
				temp1[j1+1] = t1;
			}
		}
}

int accept1(processes1 P1[]){
	int i1,n1;
	printf("\n Enter total no. of processes : ");
	scanf("%d",&n1);
	for(i1=0;i1<n1;i1++)
	{
		printf("\n PROCESS [%d]",i1+1);
		printf(" Enter process name : ");
		scanf("%s",&P1[i1].name1);
		fflush(stdin);
		printf(" Enter arrival time : ");
		scanf("%d",&P1[i1].at1);
if(P1[i1].at1<0)
	exit(0);
		printf(" Enter burst time : ");
		scanf("%d",&P1[i1].bt1);
if(P1[i1].bt1<=0)
	exit(0);
		printf(" Enter priority : ");
		scanf("%d",&P1[i1].prt1);
		printf("\n");
if(P1[i1].prt1<=0)
	exit(0);
	}
	printf("\n\n\n\n");
	printf("+-----+------------+--------------+----------+");
      printf("\n| PID | Burst time | Arrival time | Priority |");
      printf("\n+-----+------------+--------------+----------+");
	for(i1=0;i1<n1;i1++)
      printf("\n| %2s  |    %2d      |    %2d        |    %2d    |",P1[i1].name1,P1[i1].bt1,P1[i1].at1,P1[i1].prt1,P1[i1].wt1,P1[i1].ta1);
	return n1;
}



void PRT_P1(processes1 P1[],int n1){
	int i1,t_total1=0,tcurr1,b1[10],j1,x1,min_pr1;
	int sumw1=0,sumt1=0;
	float avgwt1=0.0,avgta1=0.0;
	processes1 temp1[10],t1;

	for(i1=0;i1<n1;i1++){
		temp1[i1]=P1[i1];
		t_total1+=P1[i1].bt1;
	}

	b_sort1(temp1,n1);

	for(i1=0;i1<n1;i1++)
		b1[i1] = temp1[i1].bt1;

	i1=j1=0;
	printf("\n\n\n\n\n***********************GANTT CHART*********************\n\n\n | %d | %s |",i1,temp1[i1].name1);
	for(tcurr1=0;tcurr1<t_total1;tcurr1++)
	{

		if(b1[i1] > 0 && temp1[i1].at1 <= tcurr1)
			b1[i1]--;

		if(i1!=j1)
			printf(" %d | %s |",tcurr1,temp1[i1].name1);

		if(b1[i1]<=0 && temp1[i1].flag1 != 1)
		{
			temp1[i1].flag1 = 1;
			temp1[i1].wt1 = (tcurr1+1) - temp1[i1].bt1 - temp1[i1].at1;
			temp1[i1].ta1 = (tcurr1+1) - temp1[i1].at1;
			sumw1+=temp1[i1].wt1;
			sumt1+=temp1[i1].ta1;
		}
		j1=i1;
		min_pr1 = 999;
		for(x1=0;x1<n1;x1++){

			if(temp1[x1].at1 <= (tcurr1+1) && temp1[x1].flag1 != 1){

				if(min_pr1 != temp1[x1].prt1 && min_pr1 > temp1[x1].prt1){
					min_pr1 = temp1[x1].prt1;
					i1=x1;
				}
			}
		}

	}
	printf(" %d",tcurr1);
	avgwt1 = (float)sumw1/n1;
	avgta1 = (float)sumt1/n1;
	printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt1,avgta1);
}


void main()
{


	processes1 P1[10];
	int ch1,n1;
	printf("***************** PRIORITY SCHEDULING ALGORITHM ************\n");
printf("\n\n NOTE:");
printf("\n As we assumed that CPU is not idle");
printf("\n therefore: \n\t   Atleast one process must have arrival time '0'");
printf("\n\t   Priority must be in natural number");
printf("\n\t   Burst time must be a natural number\n\n");
    n1=accept1(P1);

    printf("\n+-----+------------+--------------+----------+");PRT_P1(P1,n1);

}
