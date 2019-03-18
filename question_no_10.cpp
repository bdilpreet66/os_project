#include<stdio.h>
#include<math.h>

main(){
	
	int distance_covered=0 , cur_pos=0 , prev_pos=0;
	bool flag = true;
	
	while(flag){
		printf("Would you like to enter the address of the request or not:\n y: yes\n n: no\n");
		char chr;
		chr = getchar();
	
		// This part is what was originally asked in the question
		if(chr=='n'){
			cur_pos=143;
			prev_pos=125;
			int my_queue[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
			
			prev_pos = cur_pos;
			for(int i=0;i<9;i++){
				cur_pos = my_queue[i];
				distance_covered = distance_covered + abs(cur_pos-prev_pos);
				prev_pos = cur_pos;
			}
			
			printf("\nThe total cylinders covered are : %d",distance_covered);
			flag = false;
		}
		
		//This part is what i have added to the question to make the program more dynamic
		else if(chr=='y'){
			
			int n;
			
			printf("Enter the total number of processes : ");
			scanf("%d",&n);
			
			int my_queue[n];
			printf("Enter the cylinders to be given to the process in order : ");
			for(int i=0;i<n;i++){
				scanf("%d",&my_queue[i]);
			}
			
			for(int i=0;i<n;i++){
				cur_pos = my_queue[i];
				distance_covered = distance_covered + abs(cur_pos-prev_pos);
				prev_pos = cur_pos;
			}
			
			printf("The total cylinders covered are : %d",distance_covered);
			flag = false;
		}
		else
			printf("Please enter a valid option");
	}
}
