#include <stdio.h>
#include <time.h>
#pragma warning(disable: 4996)
#define SIZE 4000

void Insertion(int* num, int len)
{
	int temp, i, j;
	for (i = 1; i < len; i++) {
		temp = num[i];
		for (j = i; j > 0 && num[j - 1] > temp; j--)
			num[j] = num[j - 1];

		num[j] = temp;
	}
}


int main(void)
{
	int i = 0, num;
	int arr[SIZE];

	for (int j = SIZE; j > 0; j--) {
		arr[i] = j;
		i++;
	}

	for (i = 0; i < SIZE; i++)
		printf("%d\n", arr[i]);

	time_t start, end;
	start = clock();
	Insertion(arr, SIZE);
	end = clock();

	//Á¤·Ä ÈÄ
	for (i = 0; i < SIZE; i++)
		printf("%d\n", arr[i]);

	printf("\nThe time for sorting %d numbers in worst case is %d ms.\n", SIZE, (int)(end - start));

	return 0;
}