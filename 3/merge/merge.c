#include <stdio.h>
#include <time.h>
#include <Windows.h>
#define SIZE 4000

void Merge(int* num, int start, int center, int end)
{
	int sorted[SIZE];
	int s, c, ind;
	int i = 0;
	s = start;
	c = center + 1;
	ind = 0;

	while (s <= center && c <= end) {
		if (num[s] <= num[c]) {
			sorted[ind] = num[s];
			s++;
		}
		else {
			sorted[ind] = num[c];
			c++;
		}
		ind++;
	}

	if (s > center)
		for (int i = c; i <= end; i++)
			sorted[ind++] = num[i];
	else
		for (int i = s; i <= center; i++)
			sorted[ind++] = num[i];

	while (ind > 0) {
		ind--;
		num[start + ind] = sorted[ind];
	}
}

void Sorting(int* num, int start, int end)
{
	if (start >= end)
		return;
	else {
		int center = (start + end) / 2;

		Sorting(num, start, center);
		Sorting(num, center + 1, end);

		Merge(num, start, center, end);
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
	Sorting(arr, 0, SIZE - 1);
	QueryPerformanceCounter(&EndTime);
	Time = (double)(EndTime.QuadPart - BeginTime.QuadPart) / (double)(Frequency.QuadPart);

	printf("\nAfter sorting\n");
	for (i = 0; i < SIZE; i++) {
		printf("%4d  ", arr[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}

	printf("\n\nThe time for Merge sorting %d numbers in worst case is %lf micro-second.\n", SIZE, Time);

	return 0;
}