#include<stdio.h>

main(){
	
	int distance_covered=0 , cur_pos=143 , prev_pos=125;
	
	printf("Would you like to enter the address of the request or not:\n y: yes\n n:no");
	char chr;
	chr = getche();
	
	if(chr=='n'){
		int my_queue = [86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130];
		
		prev_pos = cur_pos;
		
		for(int i=0;i<my_queue.length();i++){
			cur_pos = my_queue[i]
			distance_covered = distance_covered + (cur_pos-prev_pos);
		}
		
		printf("The total cylinders covered are : %d",distance_covered);
	}
}
