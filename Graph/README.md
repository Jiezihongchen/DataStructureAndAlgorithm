|       文件名        |     描述     | 内容 |
| :-----------------: | :----------: | :--: |
| adjacencyMatrix.cpp |   邻接矩阵   |      |
| adjacencyTable.cpp  |    邻接表    |      |
|    dijkstra.cpp     | Dijkstra算法 |      |
|                     |              |      |

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
    for(int i=0; i<n; i++)
        if(visited[i]==false&&graph[u][i]!=0)
            DFS(i);
}
void DFSTrave() {
    for(int i=0; i<n; i++)
        if(visited[i]==false)
            DFS(i);
}
void BFS(int u) {
    queue<int> q;
    q.push(u);
    int temp;
    while(!q.empty()) {
        temp = q.front();
        visited[temp]=true;
        q.pop();
        for(int i=0; i<n; i++)
            if(graph[temp][i]!=0&&visited[i]==false)
                q.push(i);
    }
}
void BFSTrave() {
    for(int i=0; i<n; i++)
        if(visited[i]==false)
            DFS(i);
}
int main() {
    return 0;
}
```

## 邻接表

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
    for(int i=0; i<adj[u].size();i++)
        if(visited[adj[u][i]]==false)
            DFS(adj[u][i]);
}
void DFSTrave() {
    for(int i=0; i<n; i++)
        if(visited[i]==false)
            DFS(i);
}
void BFS(int u) {
    queue<int> q;
    q.push(u);
    int temp;
    while(!q.empty()) {
        temp = q.front();
        visited[temp] = true;
        q.pop();
        for(int i=0; i<adj[temp].size(); i++) {
            int k = adj[temp][i];
            if(visited[k]==false) q.push(k);
        }
    }
}
void BFSTrave() {
    for(int u=0; u<n; u++)
        if(visited[u]==false)
            BFS(u);
}
int main() {
    return 0;
}
```

------

# 最短路径

给定图G(V, E)，求一条从起点到终点的路径，使得这条路径上经过的所有的边权之和最小。

## 1. Dijkstra算法

Dijkstra算法解决的是<u>**单源最短路径问题**</u>，即给定图G(V, E)和起点S，求从起点S到达其他顶点的最短距离。

Dijkstra算法无法解决<u>**有负权边**</u>的最短路径问题。

<u>**算法策略：**</u>

1. 每次从集合V-S()中选择与起点S的最短距离最小的一个顶点(u)，访问并加入集合S()。
2. 令顶点u位中介点，优化起点S与所有从u能到达的顶点V之间的最短距离。

```c++
Dijkstra(G, dis[], s) {
	初始化dis[]
	for (循环n次) {
		u = 使dis[u]最小的还未被访问的顶点的标号
		vis[u] = true
		for (从u出发能达到的所有顶点v) {
			if (v未被访问 and 以u为中介点使s到顶点V的最短距离dis[v]更优)
				优化dis[v]
		}
	}
}
```

## 2. Bellman-Ford算法

Bellman-Ford算法可以解决<u>**单源最短路径问题**</u>，也可以处理<u>**有负权边**</u>的情况。

## 3. SPFA算法

## 4. Floyd算法

Floyd算法用来解决<u>**全源最短路径问题**</u>，即对给定的图G(V, E)，求任意两点u，v之间的最短路径长度。

<u>**算法策略：**</u>

如果存在顶点k，使得以k作为中介点时顶点i和顶点j的当前最短距离缩短，则使用顶点k作为顶点i和顶点j的中介点。

```c++
枚举顶点k
    以顶点k作为中介点，枚举所有顶点i和j
    	if (dis[i][k] + dis[k][j] < dis[i][j])
            dis[i][j] = dis[i][k] + dis[k][j]
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

