#include <stdio.h>
#include <stdlib.h>

struct process_structure{
	int process_ID;
	int arrival_time;
	int burst_time;
	int priority;
	int queue_ID;
}process_structure;

struct Queue
{
        int capacity=50;
        int size=0;
        int front=0;
        int rear=-1;
        int *process_id;
}Queue;

void Dequeue(Queue *Q)
{
    /* Removing an element is equivalent to incrementing index of front by one */
        
    Q->size--;
    Q->front++;
    /* As we fill elements in circular fashion */
    if(Q->front==Q->capacity)
    {
        Q->front=0;
    }
}

int front(Queue *Q)
{
    /* Return the element which is at the front*/
    return Q->process_id[Q->front];
}

void Enqueue(Queue *Q,int element)
{
    /* If the Queue is full, we cannot push an element into it as there is no space for it.*/
    if(Q->size == Q->capacity)
    {
        printf("Queue is Full\n");
    }
    else
    {
        Q->size++;
        Q->rear = Q->rear + 1;
        /* As we fill the queue in circular fashion */
        if(Q->rear == Q->capacity)
        {
            Q->rear = 0;
        }
        /* Insert the element in its rear side */ 
        Q->process_id[Q->rear] = element;
    }
}


main(){
	int n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	Queue *q1 ,*q2;
	
	for(int i=0;i<n;i++){
		
	}	
}
