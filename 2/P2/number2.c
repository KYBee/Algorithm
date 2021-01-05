#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void IsPalindrome(char* str)
{
	int len = 0;				//variable which stores the length of string

	while (str[len] != 0) {
		len++;
	}

	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
		{
			printf("Not palindrome. \n");
			return;
		}
	}
	printf("Palindrome. \n");
}

int main(void)
{
	char panlin[30];			//array for getting string

	printf("Enter word : ");
	scanf("%s", &panlin);
	IsPalindrome(panlin);
	return 0;
}