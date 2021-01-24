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
```c++
int n, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};
void dijstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (d[j] < MIN && vis[j] == false) {
                MIN = d[j]; u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[u] == false && g[u][v] >= 0 && d[v] > d[u] + graph[u][v])
                d[v] = d[u] + graph[u][v];
        }
    }
}
```

------

## 2. Floyd算法

Floyd算法用来解决<u>**全源最短路径问题**</u>，即对给定的图G(V, E)，求任意两点u，v之间的最短路径长度。

<u>**算法策略：**</u>

如果存在顶点k，使得以k作为中介点时顶点i和顶点j的当前最短距离缩短，则使用顶点k作为顶点i和顶点j的中介点。

```c++
枚举顶点k
    以顶点k作为中介点，枚举所有顶点i和j
    	if (dis[i][k] + dis[k][j] < dis[i][j])
            dis[i][j] = dis[i][k] + dis[k][j]
```

```c++
void Floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}
```

