#include <stdio.h>
#include <time.h>
#pragma warning(disable: 4996)
#define SIZE 10
#define BUCKET_NUM 2

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


void bucket(int* num, int len)
{
	int volume = SIZE / BUCKET_NUM;
	int b[BUCKET_NUM][SIZE/BUCKET_NUM];
	int temp[BUCKET_NUM] = {0};

	for (int i = 0; i < len; i++)
		b[(num[i] - 1) / volume][temp[(num[i] - 1) / volume]++] = num[i];

	for (int i = 0; i < BUCKET_NUM; i++)
		Insertion(b[i], volume);
	
	int k = 0;

	for (int i = 0; i < BUCKET_NUM; i++)
		for (int j = 0; j < volume; j++)
			num[k++] = b[i][j];

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
	bucket(arr, SIZE);
	end = clock();

	//Á¤·Ä ÈÄ
	for (i = 0; i < SIZE; i++)
		printf("%d\n", arr[i]);

	printf("\nThe time for sorting %d numbers in worst case is %d ms.\n", SIZE, (int)(end - start));

	return 0;
}