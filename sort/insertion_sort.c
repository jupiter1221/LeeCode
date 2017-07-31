#include <stdio.h>

int insertion_sort(int sort_list[],int array_size);

void print_array(int sort_list[],int array_size);

int main(void) {
	int a[] = {1,3,3,1,2,10,8,4,11,20,9,12,13};
	print_array(a, sizeof(a)/sizeof(int));
	insertion_sort(a, sizeof(a)/sizeof(int));
	return 1;
}

void print_array(int array[],int array_size)
{
	int i = 0;
	for(; i < array_size; i++) 
	{
		printf(" %2d",array[i]);
	
	}
	printf(" \n");
}

int insertion_sort(int sort_list[],int array_size)
{
	int i = 0; //not sorted index
	int j = 0; //sorted index
	int target_tmp;
	printf("Start insertion_sort() !\n");
	for(i = 1; i < array_size; i++) {
		target_tmp = sort_list[i];
		printf("Target: %2d ",target_tmp);

		for(j = i - 1; j >= 0; j--) {
			if(target_tmp < sort_list[j]) {
				sort_list[j+1] = sort_list[j];
			}
			else
				break;
		}
		sort_list[j+1] = target_tmp;
		printf(" , find index %2d : ",j + 1);
		print_array(sort_list,array_size);
	}
}
