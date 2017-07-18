#include <stdio.h>

int seach_recursive(const int sort_list[],int array_size,int target,int right,int left);

int main(void) {
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	seach_recursive(a, sizeof(a)/sizeof(int),6,sizeof(a)/sizeof(int),0);
	return 1;
}

int seach_recursive(const int sort_list[],int array_size,int target,int right,int left)
{
	int middle;
	int static loop_times = 1;
	printf("Start search_recursive() for %d-th times !\n",loop_times++);
	printf("----right = %2d, left = %d---- \n",right, left);
	while (left <= right) {
		middle = (right + left) / 2 ;
		printf("right = %2d, left = %2d,,middle  = %2d,sort_list[middle] = %2d \n",right, left,middle,sort_list[middle]);
		if(sort_list[middle] == target) {
			printf("Find !!! %d \n",middle);
			return middle;
 		}
		else if (sort_list[middle] > target)
			return seach_recursive(sort_list,array_size,target,middle - 1,left);
		else 
			return seach_recursive(sort_list,array_size,target,right,middle + 1);	
			
	}
	printf("Can not find !\n");
}
