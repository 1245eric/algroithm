// AlgoSuite - 演算法工具箱 初始版本
// main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


void showMenu() {
    printf("\n=== Algorithm ===\n");
    printf("1. 排序演算法\n");
    printf("2. 搜尋演算法\n");
    printf("3. 圖論遍歷 (BFS / DFS)\n");
    printf("4. 最短路徑 (Dijkstra)\n");
    printf("5. 動態規劃\n");
    printf("6. 二元搜尋樹操作\n");
    printf("7. 並查集合併\n");
    printf("0. 離開\n");
    printf("0:離開");
}

int main() {
    int choice;
    do {
        showMenu();
        printf("請輸入選項：");
        if (scanf("%d", &choice) != 1) {
            printf("\n輸入錯誤，請輸入數字選項。\n");
            while (getchar() != '\n'); // 清除輸入緩衝區
            continue;
        }

        switch (choice) {
            case 1:
                printf("[執行排序演算法]\n");
                break;
            case 2:
                printf("[執行搜尋演算法]\n");
                break;
            case 3:
                printf("[執行圖論遍歷]\n");
                break;
            case 4:
                printf("[執行最短路徑演算法]\n");
                break;
            case 5:
                printf("[執行動態規劃]\n");
                break;
            case 6:
                printf("[執行二元搜尋樹操作]\n");
                break;
            case 7:
                printf("[執行並查集合併]\n");
                break;
            case 0:
                printf("\n感謝使用，程式結束。\n");
                break;
            default:
                printf("\n無效的選項，請重新輸入。\n");
        }
    } while (choice != 0);

    return 0;
}




void runSortDemo() {
    int arr[MAX], n;
    printf("輸入要排序的元素數量: ");
    scanf("%d", &n);
    printf("請輸入 %d 個整數: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    printf("排序結果: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void runSearchDemo() {
    int arr[MAX], n, target;
    printf("輸入陣列長度: ");
    scanf("%d", &n);
    printf("請輸入 %d 個整數（升序）: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("輸入要搜尋的數字: ");
    scanf("%d", &target);

    int low = 0, high = n - 1, found = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            printf("找到 %d 於索引 %d\n", target, mid);
            found = 1;
            break;
        } else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    if (!found) printf("未找到元素。\n");
}


int g[MAX][MAX], visited[MAX], vcount;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < vcount; i++)
        if (g[v][i] && !visited[i]) dfs(i);
}

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    memset(visited, 0, sizeof(visited));
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        for (int i = 0; i < vcount; i++) {
            if (g[curr][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void runGraphTraversalDemo() {
    int e, a, b, start, mode;
    printf("輸入頂點數: "); scanf("%d", &vcount);
    memset(g, 0, sizeof(g));
    printf("輸入邊數: "); scanf("%d", &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }
    printf("起點: "); scanf("%d", &start);
    printf("模式 (1=DFS, 2=BFS): "); scanf("%d", &mode);
    memset(visited, 0, sizeof(visited));
    printf("遍歷結果: ");
    if (mode == 1) dfs(start);
    else bfs(start);
    printf("\n");
}

void runDijkstraDemo() {
    int cost[MAX][MAX], dist[MAX], visited[MAX];
    int n, start;
    printf("輸入頂點數: "); scanf("%d", &n);
    printf("輸入圖的鄰接矩陣（不可達輸入999）:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("起點: "); scanf("%d", &start);

    for (int i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }
    dist[start] = 0; visited[start] = 1;

    for (int count = 1; count < n; count++) {
        int min = 999, u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) min = dist[i], u = i;

        visited[u] = 1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[u] + cost[u][i] < dist[i])
                dist[i] = dist[u] + cost[u][i];
    }

    printf("最短路徑: \n");
    for (int i = 0; i < n; i++)
        printf("到 %d 的距離 = %d\n", i, dist[i]);
}

// dp.c
int fib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void runDpDemo() {
    int n;
    printf("輸入要計算的 Fibonacci(n): ");
    scanf("%d", &n);
    printf("Fibonacci(%d) = %d\n", n, fib(n));
}

// bst.c
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int data) {
    if (!root) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data; node->left = node->right = NULL;
        return node;
    }
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void runBstDemo() {
    struct Node* root = NULL;
    int n, val;
    printf("輸入節點數: "); scanf("%d", &n);
    printf("請輸入節點值: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("中序遍歷: ");
    inorder(root);
    printf("\n");
}

// disjoint_set.c
int parent[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) parent[fy] = fx;
}

void runDisjointSetDemo() {
    int n, q, x, y;
    printf("輸入元素個數: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) parent[i] = i;

    printf("輸入合併操作數量: "); scanf("%d", &q);
    printf("請輸入 %d 組 union(x, y):\n", q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &x, &y);
        unionSet(x, y);
    }

    printf("集合代表：\n");
    for (int i = 0; i < n; i++)
        printf("%d -> %d\n", i, find(i));
}
