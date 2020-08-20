#include <stdio.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int binary_seach(const int sort_list[],int array_size,int target);

int main(void) {
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    printf("Data list:\n");
    for(int i=0;i< NELEMS(a);i++)
        printf(" %2d ",a[i]);
    printf("\n");
	binary_seach(a, sizeof(a)/sizeof(int),6);
	return 1;
}

int binary_seach(const int sort_list[],int array_size,int target)
{
	int middle = 0;
	int left = 0;
	//int b[] = {1,2,3,4,5,6,7,8,9};
	int right = array_size;
	//int bszie = sizeof(b);
	//printf("bsize = %d\n",bszie);

	printf("Start binary_search() !\n");
	printf("----right = %2d, left = %d---- \n",right, left);
	while (left <= right) {
		middle = (right + left) / 2 ;
		printf("right = %2d, left = %2d,,middle  = %2d,sort_list[middle] = %2d \n",right, left,middle,sort_list[middle]);
		if(sort_list[middle] == target) {
			printf("Find !!! %d \n",middle);
			return middle;
 		}
		else if (sort_list[middle] > target)
			right = middle - 1;
		else 
			left = middle + 1;	
			
	}
	printf("Can not find !\n");
}
