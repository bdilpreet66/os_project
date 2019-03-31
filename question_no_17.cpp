#include <stdio.h>
#include <stdlib.h>

struct process_structure{
	int process_ID;
	int arrival_time;
	int burst_time;
	int priority;
	int queue_ID;
}p[50];

struct Queue
{
        int capacity=50;
        int size=0;
        int front=0;
        int rear=-1;
        int process_id[50];
}q1 ,q2;

int Dequeue(struct Queue Q)
{
    /* Removing an element is equivalent to incrementing index of front by one */
        
    Q.size--;
    Q.front++;
    /* As we fill elements in circular fashion */
    if(Q.front==Q.capacity)
    {
        Q.front=0;
    }
    return Q.process_id[Q.front-1];
}

int front(struct Queue Q)
{
    /* Return the element which is at the front*/
    return (Q.process_id[Q.front]);
}

void Enqueue(struct Queue Q,int element)
{
    /* If the Queue is full, we cannot push an element into it as there is no space for it.*/
    if(Q.size == Q.capacity)
    {
        printf("Queue is Full\n");
    }
    else
    {
        Q.size++;
        Q.rear = Q.rear + 1;
        /* As we fill the queue in circular fashion */
        if(Q.rear == Q.capacity)
        {
            Q.rear = 0;
        }
        /* Insert the element in its rear side */
        Q.process_id[Q.rear] = element;
        
    }
}

//sort according to arival time
void sort_arival(int n){
	struct process_structure a;
	int min,pos;
	
	for(int i=0;i<n;i++){
		min = p[i].arrival_time;
		pos = i;	
		for(int j=0;j<n;j++){
			if(min>p[j].arrival_time){
				min = p[j].arrival_time;
				pos = j;
			}
		}
		
		if(i!=pos){
			a=p[i];
			p[i]=p[pos];
			p[pos]=a;
		}
	}
}


//this part containts scheduler config
void my_scheduler(int n){
	int index[n],i=0;
	bool flag = true;
	if(q1.front<=q1.rear){
		//code for queue 1 goes here
		while(flag){
			
		}
	}
	else{
		//code for queue 2 goes here
		if(p[front(q2)].burst_time>=2){
			p[front(q2)].burst_time=p[front(q2)].burst_time-2;	
		}
		else{
			p[front(q2)].burst_time=p[front(q2)].burst_time-1;
		}
		index[0] = Dequeue(q2);
		if(p[front(q2)].burst_time!=0){
			Enqueue(q2,index);
			p[index[0]].queue_ID=2;
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
		printf("\nEnter the process Id for the process %d :",i+1);
		scanf("%d",&val);
		p[i].process_ID = val;
		printf("\nEnter the process arival time :");
		scanf("%d",&val);
		p[i].arrival_time=val;
		printf("\nEnter the process burst time :");
		scanf("%d",&val);
		p[i].burst_time=val;
		printf("\nEnter the process priority :");
		scanf("%d",&val);
		p[i].priority=val;
	}

	//sort the processes
	sort_arival(n);
	
	//add to the queue 1
	for(int i=0;i<n;i++){
		Enqueue(q1,i);
		p[i].queue_ID=1;
	}
		
}
