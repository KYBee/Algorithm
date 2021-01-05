#include <stdio.h>
#include <time.h>
#include <Windows.h>
#pragma warning(disable: 4996)
#define SIZE 4000

void Bubble(int* num, int len)
{
	int temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 1; j < len; j++)
			if (num[j - 1] > num[j]) {
				temp = num[j];
				num[j] = num[j - 1];
				num[j - 1] = temp;
			}
	}
}


int main(void)
{
	int i = 0;
	int arr[SIZE];
	LARGE_INTEGER BeginTime, EndTime, Frequency;
	double Time;

	for (int j = SIZE; j > 0; j--) {
		arr[i] = j;
		i++;
	}

	printf("Before sorting\n");
	for (i = 0; i < SIZE; i++) {
		printf("%4d  ", arr[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&BeginTime);
	Bubble(arr, SIZE);
	QueryPerformanceCounter(&EndTime);
	Time = (double)(EndTime.QuadPart - BeginTime.QuadPart) / (double)(Frequency.QuadPart);

	printf("\nAfter sorting\n");
	for (i = 0; i < SIZE; i++) {
		printf("%4d  ", arr[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}

	printf("\n\nThe time for Bubble sorting %d numbers in worst case is %lf micro-second.\n", SIZE, Time);

	return 0;
}