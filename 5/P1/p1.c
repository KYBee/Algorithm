#include <stdio.h>
#pragma warning(disable: 4996)

int fib(int n, int * memo)
{
	if (n <= 2)
		return 1;

	if (memo[n] != NULL)			//Memo에 이미 key에 따른 value가 저장되어 있음
		return memo[n];
	else {							//Memo에 값을 새로 넣어줘야 함
		memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
		return memo[n];
	}
}

int main(void)
{
	int cnt;
	int memo[20] = { 0 };

	printf("Enter the Number (less than 20) : ");
	scanf("%d", &cnt);

	printf("The Answer is %d", fib(cnt, memo));

	return 0;
}