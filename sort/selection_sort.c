#include <stdio.h>

int selection_sort(int sort_list[],int array_size);

void print_array(int sort_list[],int array_size);

int main(void) {
	int a[] = {1,3,3,1,2,10,8,4,11,20,9,12,13};
	print_array(a, sizeof(a)/sizeof(int));
	selection_sort(a, sizeof(a)/sizeof(int));
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

int swap_subtract(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int selection_sort(int sort_list[],int array_size)
{
	int i = 0; //searched index
	int j = 0; //remainder index
	int *min;
	printf("Start selection_sort() !\n");
	for(i = 0; i < array_size; i++) {
		min = &sort_list[i];
		printf("initila  *min = %2d : ",*min);
		for(j = i + 1; j <= array_size; j++) {
			if(sort_list[j] < *min)
				min = &sort_list[j];
		}
		printf("Find min  %2d : ",*min);
		swap_subtract(&sort_list[i],min);
		print_array(sort_list,array_size);
	}
}
