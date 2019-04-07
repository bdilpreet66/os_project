#include<stdio.h>

int n=0;//total number of processes
int clock = 0;//a clock having the current time
int cur_p=9999;
int cur_index=-1;
int rr_index=0;

struct process{
	int id;//process id
	int at;//arival time
	int bt;//burst time
	int p;//priority
	int start_time[100];//index containg all the starting times of process
	int start_index=0;//current index of start_time
	int status = -1;//process status waiting: -1 , finished: 0, running:1;
	int waiting_time=0;//total time the process was in waiting
	int next_process_index=0;//next process address
	int my_index;//current process address
	int visited=0;
}proc[2][50];

int queue=0;//queue number
int q1_proc,q2_proc;//number of process in q1 qnd q2

//to sort by arrival time
void sort_arival(int n){
	struct process a;
	int min,pos;
	
	for(int i=0;i<n-1;i++){
		min = proc[queue][i].at;
		pos = i;	
		for(int j=i+1;j<n;j++){
			if(min>proc[queue][j].at){
				min = proc[queue][j].at;
				pos = j;
			}
		}
		
		if(i!=pos){
			a=proc[queue][i];
			proc[queue][i]=proc[queue][pos];
			proc[queue][pos]=a;
		}
	}
}

int get_next(int index){
	int n=0;//if 0 current process will continue runnig else it will be sent to q2
	for(int i=0;i<q1_proc;i++){
		if(proc[queue][i].at<=clock && proc[queue][i].bt!=0){
			printf("hello");
			proc[queue][i].my_index=i;
			if(proc[queue][i].p<cur_p){
				proc[queue][index].next_process_index=i;
				cur_p=proc[queue][i].p;
				n=1;
			}
		}
	}
	return n;
}

void move_to_last(){
	struct process a;
	int i=0;
	a = proc[queue][0];
	
	while(i<q2_proc-1){
		proc[queue][i]=proc[queue][i+1];
		i++;
	}
	proc[queue][i]=a;
}

void pop(){
	int i=0;
	while(i<q2_proc-1){
		proc[queue][i]=proc[queue][i+1];
		i++;
	}
	q2_proc--;
}

main(){
	int val,res_index,a;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	struct process result[n];
	q1_proc = n;
	q2_proc = 0;
	res_index = 0;
	//get the process imformation
	
	for(int i=0;i<n;i++){
		printf("\nEnter the process information for the process %d :",i+1);
		printf("\nprocess Id : ");
		scanf("%d",&val);
		proc[queue][i].id=val;
		printf("\nprocess arival time :");
		scanf("%d",&val);
		proc[queue][i].at=val;
		printf("\nprocess burst time :");
		scanf("%d",&val);
		proc[queue][i].bt=val;
		printf("\nprocess priority :");
		scanf("%d",&val);
		proc[queue][i].p=val;
	}
	
	sort_arival(q1_proc);
	
	get_next(0);
	cur_index = proc[queue][cur_index].next_process_index;
	
	while(q1_proc!=0 || q2_proc!=0){
		if(q1_proc!=0){
			printf("\nID %d",proc[queue][cur_index].id);
			printf("\nat %d",proc[queue][cur_index].at);
			printf("\nbt %d",proc[queue][cur_index].bt);
			printf("\np %d",proc[queue][cur_index].p);
			printf("\nstatus %d",proc[queue][cur_index].status);
			//for queue 1
			queue=0;
			if((proc[queue][cur_index].status!=0) && (proc[queue][cur_index].at<=clock)){
				proc[queue][cur_index].start_time[proc[queue][cur_index].start_index]=clock;
				proc[queue][cur_index].start_index++;
				clock++;
				proc[queue][cur_index].bt--;
				a=cur_index;
				if(proc[queue][cur_index].bt==0){
					q1_proc--;
					cur_p=9999;
					get_next(cur_index);
					cur_index = proc[queue][cur_index].next_process_index;
					proc[queue][a].status=0;
					result[res_index]=proc[queue][a];
					res_index++;
					for(int i=a;i<q1_proc;i++){
						proc[queue][i]=proc[queue][i+1];
					}
				}
				if(get_next(cur_index)){
					get_next(cur_index);
					cur_index = proc[queue][cur_index].next_process_index;
					proc[queue+1][rr_index]=proc[queue][a];
					rr_index++;
					q2_proc++;
					q1_proc--;
					for(int i=a;i<q1_proc;i++){
						proc[queue][i]=proc[queue][i+1];
					}
				}
			}
			else{
				clock++;
			}
		}
		else if(q2_proc!=0){
			//for queue 2
			queue=1;
			val=1;
			if(proc[queue][cur_index].status!=0){
				for(int i=0;i<2;i++){
					proc[queue][0].start_time[proc[queue][0].start_index]=clock;
					proc[queue][0].start_index++;
					clock++;
					proc[queue][0].bt--;
					if(proc[queue][0].bt==0){
						q2_proc--;
						proc[queue][0].status=0;
						result[res_index]=proc[queue][0];
						res_index++;
						val=0;
						pop();
						break;
					}
				}
				if(val){
					move_to_last();
				}
			}	
		}
		else{
			clock++;
		}
	}
	
	for(int i=0;i<=res_index;i++){
		for(int j=0;j<=result[i].start_index;j++){
			printf("\nThe process %d was running at time %d sec.",result[i].id,result[i].start_time[j]);
		}
	}
}
