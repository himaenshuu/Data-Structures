# Graph Data Structure - Interview Book

This guide is a practical graph book for interviews and competitive programming. Read it in order when learning, and use the decision maps when solving problems.

## 📚 What Is a Graph?

A graph is a non-linear data structure made of:

- **Vertices / nodes**: the objects, states, or positions
- **Edges**: the connections, relationships, or transitions

Mathematically:

```text
G = (V, E)
```

`V` is the set of vertices and `E` is the set of edges.

### 🧠 When a Problem Is Secretly a Graph

Think graph when the problem talks about:

- relationships
- roads or routes
- dependencies
- movement in a grid
- transforming one state into another
- grouping connected things
- minimum steps
- reachability
- cycles
- networks

If one thing can move, depend on, connect to, or transform into another thing, graph thinking should start.

## 🧾 Essential Terminology

| Term | Meaning |
| --- | --- |
| Vertex / Node | One entity or state |
| Edge | Connection between two nodes |
| Degree | Number of edges connected to a node |
| Indegree | Number of incoming edges in a directed graph |
| Outdegree | Number of outgoing edges in a directed graph |
| Walk | Sequence of nodes where nodes and edges may repeat |
| Trail | Sequence where edges do not repeat |
| Path | Sequence where vertices do not repeat |
| Cycle | A path that starts and ends at the same node |
| Component | A connected group of nodes |
| Self-loop | Edge from a node to itself |
| Parallel edges | Multiple edges between the same pair of nodes |
| Sparse graph | Few edges compared to possible edges |
| Dense graph | Many edges compared to possible edges |

## 🏗️ Graph Representation

Choosing the right representation makes the algorithm simpler.

### Adjacency List

Best for most interview and competitive programming problems.

```cpp
vector<vector<int>> adj(n);

for(auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

For weighted graphs:

```cpp
vector<vector<pair<int,int>>> adj(n);

for(auto [u, v, w] : edges) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
```

- Space: `O(V + E)`
- Best for sparse graphs
- Easy for DFS, BFS, Dijkstra, Prim

### Adjacency Matrix

Useful when edge lookup must be fast or the graph is dense.

```cpp
vector<vector<int>> graph(n, vector<int>(n, 0));
graph[u][v] = 1;
```

- Space: `O(V^2)`
- Edge lookup: `O(1)`
- Best for dense graphs or Floyd-Warshall

### Edge List

Useful when edges need sorting.

```cpp
vector<tuple<int,int,int>> edges;
edges.push_back({w, u, v});
```

- Best for Kruskal
- Simple for Bellman-Ford

## 🎯 Types of Graphs

### By Direction

- **Undirected graph**: edge works both ways
- **Directed graph**: edge has one direction

### By Weight

- **Unweighted graph**: every edge has equal cost
- **Weighted graph**: edges have cost, distance, time, or probability

### By Connectivity

- **Connected graph**: every node can reach every other node
- **Disconnected graph**: some nodes cannot be reached
- **Strongly connected directed graph**: every node can reach every other node following directions
- **Weakly connected directed graph**: connected if directions are ignored

### Special Graphs

- **Tree**: connected and acyclic
- **DAG**: directed acyclic graph
- **Bipartite graph**: can be split into two groups with edges only across groups
- **Complete graph**: every pair of nodes is connected

## 🧱 Graph Modeling

Graph modeling means deciding what nodes and edges represent.

### Modeling Steps

1. Decide what each node means.
2. Decide what each edge means.
3. Decide if edges are directed.
4. Decide if edges have weights.
5. Decide if the graph is explicit or implicit.
6. Choose the algorithm based on the question.

### Common Models

| Situation | Node | Edge |
| --- | --- | --- |
| Cities and roads | City | Road |
| Course schedule | Course | Prerequisite relation |
| Grid movement | Cell | Valid move |
| Word ladder | Word | One character change |
| Lock combination | State | One wheel move |
| Social network | Person | Friendship |
| Accounts merge | Email/name/account id | Same owner relation |
| Equations | Variable | Equality relation |
| Game board | Position | Legal move |

### Explicit Graph

Edges are directly given.

```cpp
vector<vector<int>> adj(n);

for(auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

### Implicit Graph

Edges are generated while solving.

```cpp
for(string next : getNextStates(state)) {
    if(!visited.count(next)) {
        visited.insert(next);
        q.push(next);
    }
}
```

### 🧠 Interview Click

If edges are not given but you can move from one state to another, it is likely an implicit graph.

## 🧮 Common Input Patterns

### Undirected Graph

```cpp
int n, m;
cin >> n >> m;

vector<vector<int>> adj(n);
for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

### Directed Graph

```cpp
adj[u].push_back(v);
```

### Weighted Graph

```cpp
vector<vector<pair<int,int>>> adj(n);
adj[u].push_back({v, w});
```

### Grid to Node Id

```cpp
int id = r * cols + c;
int r = id / cols;
int c = id % cols;
```

## 🔍 Depth-First Search

DFS explores deeply before backtracking.

### Use DFS For

- connected components
- cycle detection
- topological sort
- subtree problems
- backtracking
- bridge and articulation point algorithms
- strongly connected components

### Basic DFS

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;

    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v, adj, vis);
        }
    }
}
```

### Disconnected Graph DFS

```cpp
int components = 0;

for(int i = 0; i < n; i++) {
    if(!vis[i]) {
        dfs(i, adj, vis);
        components++;
    }
}
```

### What DFS Can Track

- `visited`
- `parent`
- `depth`
- `tin`
- `tout`
- `low`
- recursion stack

### DFS Edge Types

| Edge Type | Meaning |
| --- | --- |
| Tree edge | Discovers a new node |
| Back edge | Goes to an ancestor |
| Forward edge | Goes to a descendant |
| Cross edge | Goes between finished branches |

### 🧠 Interview Click

Use DFS when the problem says explore all, find component, detect cycle, process subtree, or recursively follow relationships.

## 🌊 Breadth-First Search

BFS explores level by level. It gives the shortest path in an unweighted graph.

### Use BFS For

- shortest path in unweighted graph
- minimum moves
- level order traversal
- nearest target
- multi-source spreading problems
- state-space search

### BFS With Distance

```cpp
vector<int> dist(n, -1);
queue<int> q;

dist[src] = 0;
q.push(src);

while(!q.empty()) {
    int u = q.front();
    q.pop();

    for(int v : adj[u]) {
        if(dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

### Path Reconstruction

```cpp
vector<int> parent(n, -1);
vector<int> path;

for(int cur = target; cur != -1; cur = parent[cur]) {
    path.push_back(cur);
}

reverse(path.begin(), path.end());
```

### 🧠 Interview Click

If the problem asks minimum steps or shortest path without weights, BFS should be your first thought.

## 🧭 Grid as Graph

A grid is a graph where each cell is a node.

### 4-Direction Movement

```cpp
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
```

### 8-Direction Movement

```cpp
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
```

### Boundary Check

```cpp
bool valid(int r, int c, int rows, int cols) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}
```

### Common Grid Problems

- Number of Islands
- Flood Fill
- Rotten Oranges
- 01 Matrix
- Shortest Path in Binary Matrix
- Pacific Atlantic Water Flow

### 🧠 Interview Click

If movement is allowed between cells, treat the grid as a graph.

## 🔥 Multi-Source BFS

Multi-source BFS starts from many nodes at once.

### Use It For

- rotten oranges
- nearest zero
- nearest exit
- spreading fire
- infection time
- distance from nearest source

```cpp
queue<pair<int,int>> q;
vector<vector<int>> dist(rows, vector<int>(cols, -1));

for(int r = 0; r < rows; r++) {
    for(int c = 0; c < cols; c++) {
        if(grid[r][c] == 0) {
            q.push({r, c});
            dist[r][c] = 0;
        }
    }
}

while(!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for(int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if(valid(nr, nc, rows, cols) && dist[nr][nc] == -1) {
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
}
```

### 🧠 Interview Click

If many starting points spread at the same time, use multi-source BFS.

## 🎮 Implicit Graphs and State-Space BFS

In an implicit graph, states are nodes and valid operations are edges.

### Examples

- Word Ladder
- Open the Lock
- Sliding Puzzle
- Minimum Knight Moves
- Minimum jumps
- Remove Invalid Parentheses

### Template

```cpp
int bfs(string start, string target) {
    queue<string> q;
    unordered_set<string> vis;
    int steps = 0;

    q.push(start);
    vis.insert(start);

    while(!q.empty()) {
        int sz = q.size();

        while(sz--) {
            string cur = q.front();
            q.pop();

            if(cur == target) return steps;

            for(string nxt : getNextStates(cur)) {
                if(!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }

        steps++;
    }

    return -1;
}
```

### 🧠 Interview Click

If the problem asks for minimum operations to transform one state into another, model it as state-space BFS.

## 🔁 Cycle Detection

Cycle detection depends on whether the graph is directed or undirected.

### Undirected Graph Using DFS

```cpp
bool dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;

    for(int v : adj[u]) {
        if(!vis[v]) {
            if(dfs(v, u, adj, vis)) return true;
        } else if(v != parent) {
            return true;
        }
    }

    return false;
}
```

### Directed Graph Using Color

```cpp
bool dfs(int u, vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1;

    for(int v : adj[u]) {
        if(color[v] == 1) return true;
        if(color[v] == 0 && dfs(v, adj, color)) return true;
    }

    color[u] = 2;
    return false;
}
```

### Directed Graph Using Kahn's Algorithm

If topological sort processes fewer than `n` nodes, a cycle exists.

### DSU Cycle Detection

Use DSU cycle detection only for undirected graphs.

### 🧠 Interview Click

- Undirected graph cycle: DFS parent or DSU
- Directed graph cycle: DFS color or Kahn
- Dependency cycle: Kahn is usually clean

## 🧭 Topological Sort

Topological sort orders nodes so every edge `u -> v` puts `u` before `v`.

It works only for DAGs.

### Use It For

- course schedule
- prerequisites
- build systems
- task ordering
- alien dictionary
- dependency resolution

### Kahn's Algorithm

```cpp
vector<int> topoSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n);

    for(int u = 0; u < n; u++) {
        for(int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> order;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }

    return order.size() == n ? order : vector<int>{};
}
```

### DFS Topological Sort

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& order) {
    vis[u] = 1;

    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v, adj, vis, order);
        }
    }

    order.push_back(u);
}
```

Reverse the final order.

### 🧠 Interview Click

If the problem has prerequisites, ordering, dependencies, or before-after constraints, think topological sort.

## 🧲 Relaxation

Relaxation is the core idea in shortest path algorithms. It tries to improve the best known distance.

```cpp
if(dist[u] != INF && dist[u] + w < dist[v]) {
    dist[v] = dist[u] + w;
}
```

### Used In

- Dijkstra
- Bellman-Ford
- Floyd-Warshall
- DAG shortest path
- 0-1 BFS

### 🧠 Interview Click

If the problem asks minimum cost, minimum time, cheapest route, or shortest weighted path, think about relaxation.

## 🛣️ Shortest Path Algorithms

### Decision Table

| Graph Type | Algorithm |
| --- | --- |
| Unweighted graph | BFS |
| Edge weights are 0 or 1 | 0-1 BFS |
| Non-negative weights | Dijkstra |
| Negative edges allowed | Bellman-Ford |
| All-pairs shortest path | Floyd-Warshall |
| Weighted DAG | Topological sort + relaxation |

### Dijkstra

Use for shortest path with non-negative weights.

```cpp
vector<long long> dijkstra(int src, vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    vector<long long> dist(n, LLONG_MAX);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d != dist[u]) continue;

        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
```

### 0-1 BFS

Use when weights are only `0` and `1`.

```cpp
vector<int> zeroOneBFS(int src, vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    deque<int> dq;

    dist[src] = 0;
    dq.push_front(src);

    while(!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                if(w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }

    return dist;
}
```

### Bellman-Ford

Use when negative edges are allowed.

```cpp
vector<int> bellmanFord(int n, int src, vector<tuple<int,int,int>>& edges) {
    const int INF = 1e9;
    vector<int> dist(n, INF);
    dist[src] = 0;

    for(int i = 0; i < n - 1; i++) {
        for(auto [u, v, w] : edges) {
            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    return dist;
}
```

### Floyd-Warshall

Use for all-pairs shortest path.

```cpp
for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][k] < INF && dist[k][j] < INF) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
```

### Shortest Path in DAG

Topologically sort the graph, then relax edges in that order.

### Important Edge Cases

- unreachable nodes
- negative weights
- negative cycles
- integer overflow
- multiple shortest paths
- wrong algorithm for weight type

## 🔗 Disjoint Set Union

DSU, also called Union-Find, maintains groups of connected elements.

It supports:

- `find(x)`: representative of `x`
- `unite(a, b)`: merge two groups
- `same(a, b)`: check if two elements are already connected

### Implementation

```cpp
class DSU {
    vector<int> parent, sz;

public:
    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa == pb) return false;

        if(sz[pa] < sz[pb]) swap(pa, pb);
        parent[pb] = pa;
        sz[pa] += sz[pb];
        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return sz[find(x)];
    }
};
```

### When Your Mind Should Click DSU

Think DSU when the problem says:

- connected components
- merge groups
- same group
- redundant connection
- number of provinces
- accounts merge
- equations equality
- minimum cost to connect
- undirected cycle detection
- edges are added one by one

### Problem Types

| Type | Signal |
| --- | --- |
| Connected components | Count groups after unions |
| Cycle detection | New edge joins nodes already connected |
| Account/group merging | Shared value means same group |
| Kruskal MST | Need avoid cycle while adding edges |
| Grid union | Adjacent valid cells join |
| Equation grouping | Equality merges variables |

### When Not to Use DSU

Do not use DSU when you need:

- shortest path
- actual path
- traversal order
- directed cycle detection
- edge deletion support
- all nodes reachable from a source

## 🧩 Connected Components

A connected component is a group of nodes where every node can reach every other node in that group.

### Undirected Graph

Use DFS, BFS, or DSU.

### Directed Graph

There are two meanings:

- **Strongly connected**: directions are respected
- **Weakly connected**: directions are ignored

### DFS/BFS vs DSU

| Need | Use |
| --- | --- |
| Traverse nodes | DFS/BFS |
| Count groups after merging | DSU |
| Check same group quickly | DSU |
| Find path or distance | DFS/BFS |

## 🧬 Strongly Connected Components

An SCC is a maximal group of nodes in a directed graph where every node can reach every other node.

### Kosaraju's Algorithm

1. Run DFS and store nodes by finish time.
2. Reverse all edges.
3. Process nodes in reverse finish order.
4. Each DFS in the reversed graph gives one SCC.

### Tarjan's Algorithm

Tarjan uses DFS, discovery time, and low-link values to find SCCs in one pass.

### Condensation Graph

If every SCC is compressed into one node, the resulting graph is always a DAG.

### 🧠 Interview Click

If the directed graph asks about mutual reachability, strongly connected groups, or compressing cycles, think SCC.

## 🔗 Low-Link Values

Low-link values tell how early a node or subtree can reach during DFS.

### Variables

- `tin[u]`: discovery time of `u`
- `low[u]`: earliest discovery time reachable from `u`

### Used For

- bridges
- articulation points
- Tarjan SCC

### Core Update

```cpp
low[u] = min(low[u], low[v]);
low[u] = min(low[u], tin[v]);
```

### 🧠 Interview Click

If removing an edge or node can break connectivity, low-link is probably involved.

## 🌉 Bridges

A bridge is an edge whose removal increases the number of connected components.

### Bridge Condition

For DFS tree edge `u - v`:

```cpp
if(low[v] > tin[u]) {
    bridges.push_back({u, v});
}
```

### Meaning

The subtree of `v` cannot reach `u` or any ancestor of `u` without using edge `u-v`.

### 🧠 Interview Click

If the problem asks critical connections, important roads, or edges whose removal disconnects the graph, think bridges.

## 📍 Articulation Points

An articulation point is a node whose removal increases the number of connected components.

### Conditions

- DFS root is an articulation point if it has more than one DFS child.
- Non-root node `u` is an articulation point if some child `v` has `low[v] >= tin[u]`.

### 🧠 Interview Click

If the problem asks critical routers, important cities, or nodes whose removal breaks the network, think articulation points.

## 🌲 Minimum Spanning Tree

An MST connects all nodes in an undirected weighted graph with minimum total edge weight.

### Important Facts

- Only for undirected weighted graphs.
- For `n` nodes, MST has `n - 1` edges.
- MST minimizes total cost, not shortest distance from one source.
- If graph is disconnected, MST does not exist for the whole graph.

### Kruskal

Sort edges and use DSU.

```cpp
int kruskal(int n, vector<tuple<int,int,int>>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int total = 0;
    int used = 0;

    for(auto [w, u, v] : edges) {
        if(dsu.unite(u, v)) {
            total += w;
            used++;
        }
    }

    return used == n - 1 ? total : -1;
}
```

### Prim

Grow the tree from one node using a min heap.

```cpp
int prim(int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> used(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    int total = 0, taken = 0;

    pq.push({0, 0});

    while(!pq.empty() && taken < n) {
        auto [w, u] = pq.top();
        pq.pop();

        if(used[u]) continue;

        used[u] = 1;
        total += w;
        taken++;

        for(auto [v, cost] : adj[u]) {
            if(!used[v]) pq.push({cost, v});
        }
    }

    return taken == n ? total : -1;
}
```

### Kruskal vs Prim

| Algorithm | Best When |
| --- | --- |
| Kruskal | Edge list is natural |
| Prim | Adjacency list is natural |

### 🧠 Interview Click

If the problem says connect all nodes with minimum total cost, think MST.

## 🎨 Bipartite Graph

A graph is bipartite if it can be colored using two colors so every edge connects different colors.

### Key Facts

- Bipartite means no odd-length cycle.
- Use BFS or DFS coloring.
- Check every component if graph is disconnected.

```cpp
bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for(int i = 0; i < n; i++) {
        if(color[i] != -1) continue;

        queue<int> q;
        q.push(i);
        color[i] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : adj[u]) {
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if(color[v] == color[u]) {
                    return false;
                }
            }
        }
    }

    return true;
}
```

### 🧠 Interview Click

If the problem asks to split nodes into two groups with conflict edges, think bipartite.

## 🧵 Euler Path and Euler Circuit

Euler path uses every edge exactly once. Euler circuit uses every edge exactly once and returns to the start.

### Undirected Rules

| Type | Condition |
| --- | --- |
| Euler circuit | Every node has even degree |
| Euler path | Exactly 0 or 2 nodes have odd degree |

### Directed Rules

| Type | Condition |
| --- | --- |
| Euler circuit | Every node has indegree equal to outdegree |
| Euler path | One start has outdegree = indegree + 1, one end has indegree = outdegree + 1 |

### Algorithm

Use Hierholzer's algorithm.

### 🧠 Interview Click

If the problem asks to use every edge, ticket, or pair exactly once, think Euler path.

## 🌳 Trees as Graphs

A tree is a connected graph with no cycles.

### Properties

- A tree with `n` nodes has `n - 1` edges.
- There is exactly one path between two nodes.
- Removing one edge disconnects the tree.
- Adding one edge creates a cycle.

### Common Tree Graph Concepts

- root
- parent
- depth
- subtree size
- ancestor
- LCA
- diameter
- tree DP
- rerooting

### Diameter of Tree

The longest path between any two nodes.

Common method:

1. BFS/DFS from any node to find farthest node `a`.
2. BFS/DFS from `a` to find farthest node `b`.
3. Distance from `a` to `b` is the diameter.

### LCA and Binary Lifting

Lowest Common Ancestor is the deepest common ancestor of two nodes in a rooted tree.

Binary lifting stores `up[node][j]`, the `2^j`-th ancestor of `node`.

Use it for:

- many ancestor queries
- distance between two tree nodes
- kth ancestor
- path queries

### 🧠 Interview Click

If graph has `n` nodes and `n - 1` edges and is connected, treat it as a tree.

## 🚰 Max Flow and Matching

Max flow sends the maximum possible flow from a source to a sink through edges with capacities.

### Terms

| Term | Meaning |
| --- | --- |
| Source | Starting point of flow |
| Sink | Ending point of flow |
| Capacity | Maximum flow edge can carry |
| Residual graph | Remaining capacity graph |
| Augmenting path | Path that can still carry flow |

### Ford-Fulkerson Idea

1. Start with zero flow.
2. Find an augmenting path.
3. Push possible flow through it.
4. Update residual capacities.
5. Repeat until no augmenting path exists.

### Edmonds-Karp

Edmonds-Karp is Ford-Fulkerson using BFS for augmenting paths.

### Bipartite Matching

Bipartite matching can be modeled as max flow:

- Source connects to left side.
- Left side connects to compatible right side.
- Right side connects to sink.
- Maximum flow equals maximum matching.

### 🧠 Interview Click

If the problem asks maximum pairing, assignment, capacity, or resource distribution, think max flow or bipartite matching.

## 🧠 Final Interview Decision Map

| Problem Says | Think |
| --- | --- |
| Explore all nodes | DFS/BFS |
| Count components | DFS/BFS/DSU |
| Minimum steps | BFS |
| Many starting points spread | Multi-source BFS |
| Grid movement | Grid BFS/DFS |
| State transformation | State-space BFS |
| Shortest path with non-negative weights | Dijkstra |
| Weights are only 0 and 1 | 0-1 BFS |
| Negative weights | Bellman-Ford |
| All-pairs shortest path | Floyd-Warshall |
| Directed weighted acyclic graph | Topological shortest path |
| Prerequisites or dependencies | Topological sort |
| Merge groups | DSU |
| Undirected cycle | DFS parent or DSU |
| Directed cycle | DFS color or Kahn |
| Connect all with minimum cost | MST |
| Critical edge | Bridge |
| Critical node | Articulation point |
| Mutual reachability in directed graph | SCC |
| Split into two groups | Bipartite graph |
| Use every edge exactly once | Euler path |
| Tree ancestor queries | LCA |
| Maximum pairing | Bipartite matching |
| Flow with capacities | Max flow |

## 🚨 Common Mistakes

- Forgetting disconnected components
- Mixing directed and undirected edge insertion
- Using DFS when BFS is needed for minimum steps
- Using Dijkstra with negative weights
- Not using `long long` for large distances
- Not checking grid boundaries
- Forgetting 1-indexed to 0-indexed conversion
- Using DSU for directed cycle detection
- Not handling unreachable nodes
- Not marking visited at the right time
- Forgetting that topo sort works only for DAGs
- Confusing MST with shortest path

## ✅ Study Order

1. Representation and graph modeling
2. DFS and BFS
3. Grid BFS/DFS
4. Cycle detection
5. Topological sort
6. Shortest paths
7. DSU
8. MST
9. Bipartite graph
10. SCC
11. Bridges and articulation points
12. Trees, LCA, and diameter
13. Euler path
14. Max flow and matching
