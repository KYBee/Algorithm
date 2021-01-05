#include <stdio.h>
#pragma warning(disable:4996)
#define INF 1000000
#define MAX 10

char vertices[] = "stxzy";
int dist[MAX];
int pred[MAX];
int visited[MAX];

void Print_path(int i, int start) {

    int temp;

    printf("\ns to %c = %d", vertices[i], dist[i]);
    printf("\nPath = %c", vertices[i]);
    temp = i;

    while (temp != start) {
        temp = pred[temp];
        printf(" <-%c", vertices[temp]);
    }

    printf("\n");
}

void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX];
    int count, min, nextnode = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = Graph[i][j];

    for (int i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        min = INF;

        for (int i = 0; i < n; i++)
            if (dist[i] < min && visited[i] != 1) {
                min = dist[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        for (int i = 0; i < n; i++)
            if (visited[i] != 1)
                if (min + cost[nextnode][i] < dist[i]) {
                    dist[i] = min + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    // Printing the distance
    printf("\nTotal Cost From s\n");
    printf("=====================");
    printf("\n     %c   %c   %c   %c   \n", vertices[1], vertices[2], vertices[3], vertices[4]);
    printf("=====================");
    printf("\n S |");
    for (int i = 0; i < n; i++)
        if (i != start) {
            printf("%3d ", dist[i]);
        }
    printf("\n=====================");

    printf("\n\nShortest Path\n");

    Print_path(3, 0);
    Print_path(4, 0);

}

int main(void)
{
    int Graph[MAX][MAX] = {
        {0, 3, 0, 0, 5},
        {0, 0, 6, 0, 2},
        {0, 0, 0, 2, 0},
        {3, 0, 7, 0, 0},
        {0, 1, 4, 6, 0}
    };

    int n = 5;
    int u = 0;

    Dijkstra(Graph, n, u);

    return 0;
}