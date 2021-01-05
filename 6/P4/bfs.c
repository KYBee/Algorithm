#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

#define MAX 30
#define TOTAL 8
#define White 1
#define Gray 2
#define Black 3

int queue[MAX];
int Table[TOTAL][TOTAL] = {
    {0, 1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 1, 0}
};
char adj[TOTAL][4] = {
    {'s', 'v'},
    {'r', 'w'},
    {'w', 'x', 'u'},
    {'t', 'x', 'y'},
    {'r'},
    {'s', 't', 'x'},
    {'t', 'u', 'w', 'y'},
    {'u', 'x'}
};

int front = -1, rear = -1;

int count_edge(int u)
{
    int cnt = 0;
    for (int i = 0; i < TOTAL; i++) {
        if (Table[u][i] == 1)
            cnt++;
    }

    return cnt;
}

void enqueue(int vertex)
{
    if (rear == TOTAL - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int isEmpty_queue(void)
{
    if (front == -1 || front >= rear)
        return 1;
    else
        return 0;
}

int dequeue(void)
{
    int delete_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front + 1;
    return delete_item;
}

// vertex name 0, d 1, pi 2, col 3
void BFS(int Graph[][4], int s)
{
    int u, i = 0, num = 0, v;

    Graph[s][1] = 0;
    Graph[s][2] = 0;
    Graph[s][3] = Gray;

    num = count_edge(s);

    for (int i = 0; i < num; i++) {
        if (Table[s][i] == 1)
            enqueue(i);
    }

    while (!isEmpty_queue())
    {
        i = 0;
        v = 0;
        u = dequeue();
        num = count_edge(u);

        for (int i = 0; i < num; i++) {
            char temp = adj[u][i];
            for (int j = 0; j < TOTAL; j++) {
                if (temp == Graph[j][0]) {
                    v = j;
                    break;
                }
            }
            if (Graph[v][3] == Black) {
                Graph[v][1] = Graph[u][1] + 1;
                Graph[v][2] = Graph[u][2];
                enqueue(v);
            }

        }
        Graph[u][3] = Black;
    }
}

void Get_Node(int i, int Graph[][4], char c, int d, char pi, int color)
{
    Graph[i][0] = c;
    Graph[i][1] = d;
    Graph[i][2] = pi;
    Graph[i][3] = color;
}

int main(void)
{
    int Graph[TOTAL][4];

    Get_Node(0, Graph, 'r', 0, 0, White);
    Get_Node(1, Graph, 's', 0, 0, White);
    Get_Node(2, Graph, 't', 0, 0, White);
    Get_Node(3, Graph, 'u', 0, 0, White);
    Get_Node(4, Graph, 'v', 0, 0, White);
    Get_Node(5, Graph, 'w', 0, 0, White);
    Get_Node(6, Graph, 'x', 0, 0, White);
    Get_Node(7, Graph, 'y', 0, 0, White);

    BFS(Graph, 1);      //just put number in order

    printf("  c    d    pi  \n");
    printf("================\n");
    for (int i = 0; i < TOTAL; i++)
        printf("  %c    %d    %c  \n", Graph[i][0], Graph[i][1], Graph[i][2]);

    return 0;
}