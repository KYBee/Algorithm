#include <stdio.h>
#include <time.h>
#pragma warning(disable: 4996)
#define SIZE 4000

void Quick(int* num, int start, int end)
{
	int ind;

	if (start >= end)
		return;
	else {
		ind = Partition(num, start, end);
		Quick(num, start, ind - 1);
		Quick(num, ind + 1, end);
	}
}

int Partition(int * num, int start, int end)
{
	int piv = num[end];
	int ind = start;
	int temp;

	for (int i = start; i < end; i++){
		if (num[i] <= piv) {
			temp = num[i];
			num[i] = num[ind];
			num[ind] = temp;
			ind++;
		}
	}

	temp = num[end];
	num[end] = num[ind];
	num[ind] = temp;

	return ind;
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
	Quick(arr, 0, SIZE - 1);
	end = clock();

	//Á¤·Ä ÈÄ
	for (i = 0; i < SIZE; i++)
		printf("%d\n", arr[i]);

	printf("\nThe time for sorting %d numbers in worst case is %d ms.\n", SIZE, (int)(end - start));

	return 0;
}