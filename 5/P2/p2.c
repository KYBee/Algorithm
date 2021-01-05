#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
#define ARR_NUM 3

//DP 테이블을 만드는 함수
int** Makedp(int num)           
{
    int** P = (int**)malloc(sizeof(int *) * num);
    for (int i = 0; i < num; i++)
        P[i] = (int*)malloc(sizeof(int) * num);
    return P;
}

//연산할 행렬을 만드는 함수
int** Makearr(int row, int col)
{
    int** Matrix = (int**)malloc(sizeof(int *) * row);

    for (int i = 0; i < row; i++)
        Matrix[i] = (int*)malloc(sizeof(int) * col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            //Matrix[j][i] = rand() % 5 + 1;
            Matrix[i][j] = 1;
            printf("%4d ", Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return Matrix;
}

//행렬 곱셈 함수
int** MatrixMul(int** A, int Arow, int Acol, int** B, int Brow, int Bcol)
{
    int** C = (int**)malloc(sizeof(int *) * Arow);
    for (int i = 0; i < Arow; i++)
        C[i] = (int*)malloc(sizeof(int) * Bcol);
 
    for (int i = 0; i < Arow; i++) {
        for (int j = 0; j < Bcol; j++) {
            C[i][j] = 0;
            for (int k = 0; k < Acol; k++)
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
        }
    }
    return C;
}

//순서 출력 함수
void Optimal(int ** DP_table, int i, int j)
{
    int k;
    if (i == j)
        printf("A%d", i);
    else {
        k = DP_table[i][j];
        printf("(");
        Optimal(DP_table, i, k);
        Optimal(DP_table, k + 1, j);
        printf(")");
    }
}

//최적 계산 찾기 함수
int Minmult(int** DP_table, int* d, int n)
{
    int i, j, k, diagnonal, kmin = 0;
    int** M, temp = 0;
    M = Makedp(n + 1);
    for (i = 1; i <= n; i++)
        M[i][i] = 0;
    for (diagnonal = 1; diagnonal <= n - 1; diagnonal++)
        for (i = 1; i <= n - diagnonal; i++) {
            j = i + diagnonal;
            for (k = i; k <= j - 1; k++) {
                M[i][j] = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (i == k) {
                    temp = M[i][j];
                    kmin = k;
                }
                else if (M[i][j] > temp) {
                    M[i][j] = temp;
                }
                else
                    kmin = k;
            }
            DP_table[i][j] = kmin;
        }
    return M[1][n];
}

int main(void)
{
    int Plist[ARR_NUM + 1] = { 0 };
    int** DP_table;
    int** C = (int**)malloc(0);
    int** Matrix = (int**)malloc(0);
    int result;

    DP_table = Makedp(ARR_NUM);
    Matrix = (int**)malloc(sizeof(int) * ARR_NUM);

    for (int i = 0; i <= ARR_NUM; i++) {
        printf("p%d = ", i);
        scanf("%d", &Plist[i]);
    }

    for (int i = 0; i < ARR_NUM; i++) {
        Matrix = Makearr(Plist[i], Plist[i + 1]);
    }





    result = Minmult(DP_table, Plist, ARR_NUM);
    printf("\nArray Multiplication Order is ");
    Optimal(DP_table, 1, ARR_NUM);
    printf("\nMinimum Multiplication is %d\n", result);

    return 0;
}
