#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = 0, rear = 0;
int numVertices;


void enqueue(int v) {
    queue[rear++] = v;
}
int dequeue() {
    return queue[front++];
}

// BFS 演算法
void bfs(int startVertex) {
    for (int i = 0; i < numVertices; i++)
        visited[i] = 0;

    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("BFS traversal: ");
    while (front != rear) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS 演算法
void dfsUtil(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && !visited[i])
            dfsUtil(i);
    }
}

void dfs(int startVertex) {
    for (int i = 0; i < numVertices; i++)
        visited[i] = 0;

    printf("DFS traversal: ");
    dfsUtil(startVertex);
    printf("\n");
}

int main() {
    int edges, src, dest, startVertex;
    char mode;

    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // 初始化圖
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            graph[i][j] = 0;

    printf("Enter edges (format: src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }

    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    printf("Enter traversal mode (b for BFS, d for DFS): ");//選擇演算法
    scanf(" %c", &mode);

    if (mode == 'b' || mode == 'B')
        bfs(startVertex);
    else if (mode == 'd' || mode == 'D')
        dfs(startVertex);
    else
        printf("Invalid mode.\n");

    return 0;
}
