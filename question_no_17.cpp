#include <stdio.h>
#include <stdlib.h>

static int cur_pos=0;

struct process_structure{
	int process_ID;
	int arrival_time;
	int burst_time;
	int priority;
	int queue_ID;
	int Num;
	int Finish_time;
	int Remaining_time;
	int Waiting_time;
	int Start_time;
	int Res_time;
}p1[50],p2[50];

//sort according to arival time
void sort_arival(int n){
	struct process_structure a;
	int min,pos;
	
	for(int i=0;i<n-1;i++){
		min = p1[i].arrival_time;
		pos = i;	
		for(int j=i+1;j<n;j++){
			if(min>p1[j].arrival_time){
				min = p1[j].arrival_time;
				pos = j;
			}
		}
		
		if(i!=pos){
			a=p1[i];
			p1[i]=p1[pos];
			p1[pos]=a;
		}
	}
}


//this part containts scheduler config
void priority_sort(int start,int end){
	struct process_structure a;
	int max,pos;
	
	for(int i=start;i<=end-1;i++){
		max = p1[i].priority;
		pos = i;
		for(int j=i+1;j<=end;j++){
			if(max>p1[j].priority){
				max = p1[j].priority;
				pos = j;
			}
		}
		
		if(i!=pos){
			a=p1[i];
			p1[i]=p1[pos];
			p1[pos]=a;
		}
	}
}

//the main function
main(){
	int n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int val;
	
	//get the process imformation
	for(int i=0;i<n;i++){
		printf("\nEnter the process information for the process %d :",i+1);
		printf("\nprocess Id : ");
		scanf("%d",&val);
		p1[i].process_ID = val;
		printf("\nprocess arival time :");
		scanf("%d",&val);
		p1[i].arrival_time=val;
		printf("\nprocess burst time :");
		scanf("%d",&val);
		p1[i].burst_time=val;
		printf("\nprocess priority :");
		scanf("%d",&val);
		p1[i].priority=val;
		p1[i].Remaining_time=p[i].burst_time;
		p1[i].Num = i+1;
	}

	//sort the processes
	int start_pos,end_pos,z;
	bool flag;
	z=0;
	sort_arival(n);
	start_pos=0;
	end_pos=0;
	while(z<n){
		start_pos=end_pos;
		flag=true;
		while(flag){
			if(p1[z].arrival_time==p1[z+1].arrival_time){
				end_pos++;
			}
			else{
				end_pos++;
				flag = false;
			}
			z++;
		}
		priority_sort(start_pos,end_pos-1);
	}
	
	while(true){
		if(q1[0]!=NULL){
		
		}
	}
	
		
}
