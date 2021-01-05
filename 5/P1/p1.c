#include <stdio.h>
#pragma warning(disable: 4996)

int fib(int n, int * memo)
{
	if (n <= 2)
		return 1;

	if (memo[n] != NULL)			//Memo�� �̹� key�� ���� value�� ����Ǿ� ����
		return memo[n];
	else {							//Memo�� ���� ���� �־���� ��
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