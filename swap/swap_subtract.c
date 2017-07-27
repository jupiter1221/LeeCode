#include <stdio.h>
#include <stdlib.h>

int swap_subtract(int *a, int *b);

int main(void) {
	int *a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	*a = -10;
	*b = 27;
	swap_subtract(a, b);

clean:
	free(a);
	free(b);
	return 1;
}

int swap_subtract(int *a, int *b)
{
	printf("Befor swap a=%2d, b=%2d \n",*a,*b);
	*a=*a + *b;
	*b=*a - *b;
	*a=*a - *b;
	printf("After swap a=%2d, b=%2d \n",*a,*b);
}
