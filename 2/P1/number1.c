#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int n;					//the value of n from user
	int k = 0;				//counting powers
	int result = 1;			//result value of 2^k

	printf("enter the value of n: ");
	scanf("%d", &n);
	
	for(;;){
		if (result > n)
			break;
		result *= 2;
		k++;
	}

	printf("the largest k which satisfying 2^k <= n is %d\n", k-1);

	return 0;
}