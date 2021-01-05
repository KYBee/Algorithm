#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define Xlen 7
#define Ylen 6

void Print_LCS(int B[][Ylen + 1], char X[], int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (B[i][j] == 3) {
        Print_LCS(B, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (B[i][j] == 2)
        Print_LCS(B, X, i - 1, j);
    else if (B[i][j] == 1)
        Print_LCS(B, X, i, j - 1);
}

int main(void)
{
    char X[Xlen + 1];
    char Y[Ylen + 1];
    int LCS[Xlen + 1][Ylen + 1];
    int B[Xlen + 1][Ylen + 1] = { 0 };
    //left == 1, up == 2, leftup == 3

    printf("\nString X: ");
    scanf("%s", X);

    printf("\nString Y: ");
    scanf("%s", Y);


    /*Length - LCS*/
    printf("Matrix\n");

    for (int i = 0; i <= Ylen; i++)
        LCS[0][i] = 0;

    for (int i = 0; i <= Xlen; i++)
        LCS[i][0] = 0;

    for (int i = 1; i <= Xlen; i++) {

        for (int j = 1; j <= Ylen; j++) {

            if (X[i - 1] == Y[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                B[i][j] = 3; //LeftUp
            }
            else if (LCS[i - 1][j] >= LCS[i][j - 1]) {
                LCS[i][j] = LCS[i - 1][j];
                B[i][j] = 2; //Up
            }
            else {
                LCS[i][j] = LCS[i][j - 1];
                B[i][j] = 1; //Left
            }
        }
    }

    for (int i = 0; i <= Xlen; i++) {
        for (int j = 0; j <= Ylen; j++)
            printf("%2d ", LCS[i][j]);

        printf("\n");
    }

    printf("\nDirection\n");

    for (int i = 0; i <= Xlen; i++) {
        for (int j = 0; j <= Ylen; j++)
            printf("%2d ", B[i][j]);

        printf("\n");
    }

    printf("\n\nLCS = %d\n\n", LCS[Xlen][Ylen]);

    Print_LCS(B, X, Xlen, Ylen);

    return 0;
}