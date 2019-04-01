#include <stdio.h>

struct Process_Structure
{
	int Num;
	int Process_id;  //Process Id
	int Arival_time; //Process Arrival Time
	int Burst_time; //Process Bruest Time
	int Priority; //Process Priority
	int Finish_time; //Process Finish Time
	int Remaining_time; //Process Remaining  Time During Execution
	int Waiting_time; //Waiting Time
	int Start_time; //Process start Time
	int Res_time;

};

struct Process_Structure current;
//define the data type p of type struct
typedef struct Process_Structure P ;

bool sort_id(const P& x , const P& y)
{
	return x.Process_id< y.Process_id;
}

/** Sorting on the base of arrival time if that match then on Priority of Priority also  match than on the base of Process Id**/
bool sort_arrival( const P& x ,const P& y)
{
	if(x.Arival_time < y.Arival_time)
		return true;
	else if(x.Arival_time > y.Arival_time)
		return false;
	if(x.Priority < y.Priority)
		return true;
	else if(x.Priority > y.Priority)
		return false;
	if(x.Process_id < y.Process_id)
		return true;

	return false;
}


bool Numsort( const P& x ,const P& y)
{
	return x.Num < y.Num;
}

/*Sorting on the base of Priority if that same then on the base of PID*/
struct Operation
{
	bool operator()(const P& x ,const P& y)
	{
		if( x.Priority > y.Priority )
			return true;
		else if( x.Priority < y.Priority )
			return false;
		if( x.Process_id > y.Process_id )
			return true;

		return false;
		
	}
	
};


int main()
{
	int i;
	int n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	P input[n];
	P input2[n];
	P temp;
	int pq_process = 0; // for PQ process
	int rq_process = 0; // for RQ process
	int Arival_time;
	int Burst_time;
	int Process_id;
	int Priority;
	int clock;
	int total_exection_time = 0;
	
	
	for( i= 0; i< n; i++ )
	{
		printf("Enter Data for process %d :\n",i+1);
		printf("Process ID : ");
		scanf("%d",&Process_id);
		printf("Arival Time : ");
		scanf("%d",&Arival_time);
		printf("Burst Time : ");
		scanf("%d",&Burst_time);
		printf("Priority : ");
		scanf("%d",&Priority);
		temp.Num = i+1;
		temp.Process_id = Process_id;
		temp.Arival_time = Arival_time;
		temp.Burst_time = Burst_time;
		temp.Remaining_time = Burst_time;
		temp.Priority = Priority;
		input[i]=temp;
		input2[i]=input[i];
	}
	
	sort( input.begin(), input.end(), arrivalsort );
    //cout<<"arrivalsort : "<<endl;
    //my_check( input ); // To check the sort unomment it
    total_exection_time = total_exection_time + input[0].A_time;
    for( i= 0 ;i< n; i++ )
    {
    	if( total_exection_time >= input[i].A_time )
    	{
    		total_exection_time = total_exection_time +input[i].B_time;
    	}
    	else
    	{
    		int diff = (input[i].A_time - total_exection_time);
    		total_exection_time = total_exection_time + diff + B_time;

    	}
    }

	int Ghant[total_exection_time]={0}; //Ghant Chart
	for( i= 0; i< total_exection_time; i++ )
	{
		Ghant[i]=-1;
	}
	//cout<<"total_exection_time : "<<total_exection_time<<endl;

	priority_queue < P_d ,vector<Process_Data> ,comPare> pq; //Priority Queue PQ

	queue< P_d > rq; //Round Robin Queue RQ
	int cpu_state = 0; //idle if 0 then Idle if 1 the Busy
	int quantum = 4 ; //Time Quantum
	current.Pid = -2;
	current.Priority = 999999;

	for ( clock = 0; clock< total_exection_time; clock++ )
	{
		/**Insert the process with same Arrival time in Priority Queue**/
		for( int j = 0; j< n ; j++ )
		{
			if(clock == input[j].A_time)
			{
				pq.push(input[j]);
			}
		}
		

		if(cpu_state == 0) //If CPU idle
		{
			if(!pq.empty())
			{
				current = pq.top();
				cpu_state = 1;
				pq_process = 1;
				pq.pop();
				quantum = 4; 
			}
			else if(!rq.empty())
			{
				current = rq.front();
				cpu_state = 1;
				rq_process = 1;
				rq.pop();
				quantum = 4;
			}
		}
		else if(cpu_state == 1) //If cpu has any procss
		{
			if(pq_process == 1 && (!pq.empty()))
			{
				if(pq.top().Priority < current.Priority ) //If new process has high priority
				{
					rq.push(current); //push current in RQ
					current = pq.top();
					pq.pop();
					quantum = 4; 
				}
			}
			else if(rq_process == 1 && (!pq.empty())) //If process is from RQ and new process come  in PQ
			{
				rq.push(current);
				current = pq.top();
				pq.pop();
				rq_process = 0;
				pq_process = 1;
				quantum = 4 ;
			}
			

		}


		if(current.Pid != -2) // Process Execution
		{
			current.R_time--;
			quantum--;
			Ghant[clock] = current.Pid;
			if(current.R_time == 0) //If process Finish
			{
				cpu_state = 0 ;
				quantum = 4 ;
				current.Pid = -2;
				current.Priority = 999999;
				rq_process = 0;
				pq_process = 0;
			}
			else if(quantum == 0 ) //If time Qunatum of a current running process Finish
			{
				rq.push(current);
				current.Pid = -2;
				current.Priority = 999999;
				rq_process = 0;
				pq_process = 0;
				cpu_state=0;

			}

		}
		
	}


	sort( input.begin(), input.end(), idsort );
	
	for(int i=0;i<n;i++)
	{
		for(int k=total_exection_time;k>=0;k--)
		{
			if(Ghant[k]==i+1)
			{
				input[i].F_time=k+1;
				break;

			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<total_exection_time;k++)
		{

			if(Ghant[k]==i+1)
			{
				input[i].S_time=k;
				break;
			}
		}
	}
	
	sort( input.begin(), input.end(), Numsort );

	for(int i=0;i<n;i++)
	{
		input[i].Res_time=input[i].S_time-input[i].A_time;
		input[i].W_time=(input[i].F_time-input[i].A_time)-input[i].B_time;

	}
	
	for(int i=0;i<n;i++)
	{
		cout<<input[i].Pid<<" "<<input[i].Res_time<<" "<<input[i].F_time<<" "<<input[i].W_time<<endl;
		
	}	
	return 0;
}
