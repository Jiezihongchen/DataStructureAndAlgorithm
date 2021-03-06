如果一个有向图的任意顶点都无法通过一些有向边回到自身，那么称这个有向图为<u>**有向无环图**</u>（Directed Acyclic Graph，DAG）。

拓扑排序步骤：

1. 定义一个队列Q，并把所有入度为0的结点加入队列。
2. 取队首结点，输出。然后删去所有从它出发的边，并令这些边达到的顶点的入度减1，如果某个顶点的入度减为0，则将其加入队列。
3. 反复进行2操作，直到队列为空。如果队列为空时入过队的结点数目恰好为N，说明拓扑排序成功，图G为有向无环图，否则图中有环。

```c++
vector<int> G[MAXV];
int n, m, inDegree[MAXV];
bool topologicalSort() {
    int num = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
        num++;
    }
    if (num == n) return true;
    return false;
}
```

