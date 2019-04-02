#include <stdio.h>
#include <stdlib.h>


struct process_structure{
	int process_ID;
	int arrival_time;
	int burst_time;
	int priority;
	int Num=0;
	int Finish_time;
	int Waiting_time;
	int Start_time=-1;
	int stop_time;
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
	int next_index[n];
	
	//get the process imformation
	
	for(int i=0;i<n;i++){
		p1[i].Num = n;
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
		p1[i].Res_time=p1[i].burst_time;
	}

	//sort the processes
	int start_pos,end_pos,z,y;
	bool flag;
	z=0;
	y=1;
	sort_arival(n);
	start_pos=0;
	end_pos=0;
	next_index[0]=0;
	while(z<n){
		start_pos=end_pos;
		flag=true;
		while(flag){
			if(p1[z].arrival_time==p1[z+1].arrival_time){
				end_pos++;
			}
			else{
				end_pos++;
				next_index[y]=end_pos;
				y++;
				flag = false;
			}
			z++;
		}
		priority_sort(start_pos,end_pos-1);
	}
	
	int clock=0;
	int next_a_time;
	z=0;
	y=0;
	while(p1[0].Num==0 && p2[0].Num==0){
		if(p1[0]!=null){
			flag = true
			while(flag){
				b_time=p1[next_index[z]].burst_time;
				if(p1[next_index[z]].start_time==-1){
					p1[next_index[z]].start_time=clock;
					p1[next_index[z]].Res_time=clock;
				}
				else{
					p1[next_index[z]].Res_time=clock;
				}
				next_a_time = p[next_index[z+1]].arrival_time;
				if(p1[next_index[z+1]].priority<p1[next_index[z]].priority){
					if(b_time>next_a_time){
						p1[next_index[z]].burst_time = b_time - (next_a_time-clock);
						clock = clock + (next_a_time-clock);
						p1[next_index[z]].stop_time = next_a_time-1;
						printf("\n%d ran for %d",p1[next_index[z]].process_ID,(next_a_time-clock));
						p2[y]=p1[z];
						p2[y].Num++;
						
						for(int i=0;i<n-1;i++){
							p1[i]=p1[i+1]
						}
						
						n--;
						z++;
						y++;
					}
					else{
						p1[next_index[z]].burst_time = b_time - (next_a_time-clock);
						clock = clock + (next_a_time-clock);
						p1[next_index[z]].stop_time = next_a_time-1;
						printf("\n%d ran for %d",p1[next_index[z]].process_ID,(next_a_time-clock);
						
						for(int i=0;i<=n;i++){
							p1[i]=p1[i+1];
						}
						z++;
						n--;
					}
				}
				else{
					p1[next_index[z]].burst_time = b_time - (next_a_time-clock);
					clock = clock + (next_a_time-clock);
					p1[next_index[z]].stop_time = next_a_time-1;
					printf("\n%d ran for %d",p1[next_index[z]].process_ID,(next_a_time-clock);
						
					for(int i=0;i<=n;i++){
						p1[i]=p1[i+1];
					}
					z++;
					n--;
				}
				
				if(p1[0]==NULL){
					flag=false;
				}
			}
		}
		else{
			flag = true
			while(flag){
				b_time=p2[0].burst_time;
				if(p2[0].start_time==-1){
					p2[0].start_time=clock;
					p2[0].Res_time=clock;
				}
				else{
					p2[0].Res_time=clock;
				}
					if(b_time>=2){
						p2[0].burst_time = b_time - 2;
						clock = clock + 2;
						p2[0].stop_time = next_a_time-1;
						printf("\n%d ran for 2 sec",p2[0].process_ID);
						
						struct process_structure a;
						a=p2[0];
						for(int i=0;i<n-1;i++){
							p2[i]=p2[i+1]
						}
						p2[y]=a;
						
					}
					else{
						p2[0].burst_time = b_time - 1;
						clock = clock + 1;
						p2[0].stop_time = clock;
						printf("\n%d ran for 1 sec",p2[0].process_ID);
						
						for(int i=0;i<n-1;i++){
							p2[i]=p2[i+1];
						}
						
						y--;
					}
				
				if(p1[0]==NULL){
					flag=false;
				}
			}
		}
	}
}

