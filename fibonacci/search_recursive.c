#include <stdio.h>


/*f(0) = 0, f(1) = 1

*/
int fibonnacci(int number);

int main(void) {
	int n = 10;
	printf("fibonnacci(%2d) = %2d  \n",n,fibonnacci(n));

	return 1;
}

int fibonnacci(const int number)
{
	printf("--number = %2d ---- \n",number);
	if(number < 0) {
		printf("Error number !!!");
		return -1;
	}
	if(number == 1)
		return 1;
	else if (number == 0)
		return 0;
	else
		return fibonnacci(number - 1) + fibonnacci(number - 2);
}
