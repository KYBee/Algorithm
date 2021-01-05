#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable: 4996)
#define SIZE 4000


typedef struct timeval {
	long tv_sec;
	long tv_usec;
} timeval;

//div는 divide의 약자 = 몇번째 자리수 비교하는지
void Counting(int* num, int len, int div)
{
	int i;
	int* b = (int*)calloc(len, sizeof(int));
	int c[10] = {0};
	
	for (i = 0; i < len; i++)
		c[(num[i]/div)%10]++;

	for (i = 1; i < 10; i++)
		c[i] += c[i - 1];

	for (i = len - 1; i >= 0; i--){
		c[(num[i]/div)%10]--;
		b[c[(num[i]/div)%10]] = num[i];
	}

	for (i = 0; i < len; i++)
		num[i] = b[i];

	free(b);
}

void Radix(int* num, int len)
{
	int i, max = num[0];

	for (i = 0; i < len; i++)
		if (max < num[i])
			max = num[i];

	for (int i = 1; max / i > 0; i *= 10)
		Counting(num, len, i);

}


int main(void)
{
	int i = 0;
	int arr[SIZE];

	for (int j = SIZE; j > 0; j--) {
		arr[i] = j;
		i++;
	}

	for (i = 0; i < SIZE; i++)
		printf("%d\n", arr[i]);

	time_t start, end;
	start = clock();
	Radix(arr, SIZE);
	end = clock();

	//정렬 후
	for (i = 0; i < SIZE; i++)
		printf("%d\n", arr[i]);

	printf("\nThe time for sorting %d numbers in worst case is %d ms.\n", SIZE, (int)(end - start));

	return 0;
}