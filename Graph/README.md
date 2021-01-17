# 图的存储

## 1. 邻接矩阵

```c++
int graph[MAXV][MAXV] = {0};
```

## 2. 邻接表

```
vector<int> adj[MAXV];
```

------

# 图的遍历

## 1. 深度搜索(DFS)

以"<u>**深度**</u>"作为第一关键词，每次都是沿着路径到不能再前进时才退回到最近的岔道口。

```c++
DFS(u) {
	vis[u] = true
    for (从u出发能达到的所有顶点v)
        if (vis[u] == false)
            DFS(v)
}
DFSTrave(G) {
	for (G的所有顶点u)
        if (vis[u] == false)
            DFS(u)
}
```

## 2. 广度搜索(BFS)

以“<u>**广度**</u>”作为第一关键词，每次以扩散的方式向外访问顶点。

```c++
BFS(u) {
    queue q
    q.push(u)
    while (q非空) {
        u = q.front()
        q.pop()
        vis[u] = true
        for (从u出发能达到的所有顶点v)
            if (vis[v] == false)
                q.push(v)
    }
}
BFSTrave(G) {
    for (G的所有顶点u)
    	if (vis[u] == false)
        	BFS(u)
}
```

## 3. 邻接矩阵

```c++
#include<iostream>
#include<queue>
using namespace std;
const int MAXV = 255;
int n;
// 邻接矩阵
int graph[MAXV][MAXV] = {0};
bool visited[MAXV] = {false};
void DFS(int u) {
    visited[u] = true;
    for (int i = 0; i < n; i++)
        if (visited[i] == false && graph[u][i] != 0)
            DFS(i);
}
void DFSTrave() {
    for (int i = 0; i < n; i++)
        if (visited[i] == false)
            DFS(i);
}
void BFS(int u) {
    queue<int> q;
    q.push(u);
    int temp;
    while (!q.empty()) {
        temp = q.front();
        visited[temp] = true;
        q.pop();
        for (int i = 0; i < n; i++)
            if (graph[temp][i] != 0 && visited[i] == false)
                q.push(i);
    }
}
void BFSTrave() {
    for (int i = 0; i < n; i++)
        if (visited[i] == false)
            DFS(i);
}
int main() {
    return 0;
}
```

## 4. 邻接表

```c++
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAXV = 255;
int n;
// 邻接表
vector<int> adj[MAXV];
bool visited[MAXV] = {false};
void DFS(int u) {
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFS(adj[u][i]);
}
void DFSTrave() {
    for (int i = 0; i < n; i++)
        if (visited[i] == false)
            DFS(i);
}
void BFS(int u) {
    queue<int> q;
    q.push(u);
    int temp;
    while (!q.empty()) {
        temp = q.front();
        visited[temp] = true;
        q.pop();
        for (int i = 0; i < adj[temp].size(); i++) {
            int k = adj[temp][i];
            if (visited[k] == false) q.push(k);
        }
    }
}
void BFSTrave() {
    for (int u = 0; u < n; u++)
        if (visited[u] == false)
            BFS(u);
}
int main() {
    return 0;
}
```

------

# 最小生成树

## 1. Prim算法

## 2. Kruskal算法

------

# 拓扑排序

## 1. 有向无环图

## 2. 拓扑排序

------

# 关键路径

## 1. AOV网和AOE网

## 2. 最长路径

## 3. 关键路径

