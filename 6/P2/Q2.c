#include <stdio.h>
#define INF 1000
#define SIZE 8

typedef struct vertex {
    char name;
    int visited;
    int peeked;
    int index;
    int dist;
    struct vertex* pre;
}Vertex;


int front = -1;
int rear = -1;
Vertex queue[SIZE];

int is_empty() {
    return front == rear;
}

void enqueue(Vertex g[], Vertex element) {
    front = (front + 1) % SIZE;
    queue[front] = element;
}

Vertex dequeue(Vertex g[]) {
    rear = (rear + 1) % SIZE;
    return queue[rear];
}

int main()
{
    char adj[SIZE][4] = {
       {'s', 'v', '\0', '\0'},
       {'r', 'w', '\0', '\0'},
       {'u', 'w', 'x', '\0'},
       {'t', 'x', 'y', '\0'},
       {'r', '\0', '\0', '\0'},
       {'s', 't', 'x', '\0'},
       {'t', 'u', 'w', 'y'},
       {'u', 'x', '\0', '\0'}
    };

    Vertex g[SIZE];
    g[0].name = 'r';
    g[1].name = 's';
    g[2].name = 't';
    g[3].name = 'u';
    g[4].name = 'v';
    g[5].name = 'w';
    g[6].name = 'x';
    g[7].name = 'y';

    for (int i = 0; i < SIZE; i++) {
        if (g[i].name == 's') { // ¿©±â ¹Ù²ãÁÖ¸éµÊ
            g[i].dist = 0;
            g[i].index = i;
            g[i].pre = NULL;
            g[i].visited = 1;
        }
        else {
            g[i].dist = INF;
            g[i].index = i;
            g[i].pre = NULL;
            g[i].visited = 0;
        }
    }

    enqueue(queue, g[1]); // ¿©±â¶û

    Vertex u, v;

    while (!is_empty()) {
        u = dequeue(queue);
        for (int i = 0; i < 4; i++) {
            if (adj[u.index][i] != '\0') {
                char tmp = adj[u.index][i];
                for (int j = 0; j < SIZE; j++)
                    if (tmp == g[j].name) {
                        v = g[j];
                        break;
                    }
                if (!v.visited) {
                    v.dist = u.dist + 1;
                    v.pre = &u;
                    enqueue(queue, v);
                }
            }
        }
        if (u.pre != NULL)
            printf("%c: distance = %d, predecessor = %c\n", u.name, u.dist, (*(u.pre)).name);
        else
            printf("%c: distance = %d, Source\n", u.name, u.dist);
        u.visited = 1;
    }


    return 0;
}