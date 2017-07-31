#include <stdio.h>


/*f(0) = 0, f(1) = 1

*/
int fibonnacci_loop(int number);

int main(void) {
	int n = 10;
	printf("fibonnacci_loop(%2d) = %2d  \n",n,fibonnacci_loop(n));

	return 1;
}

int fibonnacci_loop(const int number)
{
	int fib_value = 0, fib_front = 0, fib_exfront = 0;
	
	printf("--number = %2d ---- \n",number);
	if(number < 0) {
		printf("Error number !!!");
		return -1;
	}

	for(int i = 0; i <= number; i++) {

		if(i == 1) {
			fib_value = 1;
			fib_front = 1;
		} else {
			fib_value = fib_exfront + fib_front;
			fib_exfront = fib_front;
			fib_front = fib_value;
		}
		printf("f(%d):fib_value  = %2d,fib_front = %2d ,fib_exfront = %2d\n",i,fib_value,fib_front,fib_exfront);
	}
	printf("Number  = %2d ---- \n",fib_value);
	return fib_value;
	

}
