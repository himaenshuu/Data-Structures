# Graph Data Structure - Complete Guide

## 📚 What is a Graph?

A **Graph** is a non-linear data structure consisting of:

- **Vertices (Nodes)**: Fundamental units represented by points
- **Edges**: Connections between vertices

**Mathematical Definition**: G = (V, E) where V is set of vertices and E is set of edges.

## 🏗️ Graph Representation

### 1. Adjacency Matrix

```cpp
vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
adjMatrix[u][v] = 1; // For unweighted graph
adjMatrix[u][v] = weight; // For weighted graph
```

- **Space**: O(V²)
- **Edge lookup**: O(1)
- **Good for**: Dense graphs

### 2. Adjacency List

```cpp
vector<vector<int>> adjList(n);
adjList[u].push_back(v);

// For weighted graphs
vector<vector<pair<int,int>>> adjList(n); // {node, weight}
adjList[u].push_back({v, weight});
```

- **Space**: O(V + E)
- **Edge lookup**: O(degree); degree is defined as number of vertices connected to a vertex
- **Good for**: Sparse graphs (most interview problems)

### 3. Edge List

```cpp
vector<pair<int,int>> edges; // {u, v}
vector<tuple<int,int,int>> edges; // {u, v, weight}
```

- Used in Kruskal's algorithm

## 🎯 Graph Types

### By Direction

1. **Directed Graph (Digraph)**: Edges have direction (u → v)
2. **Undirected Graph**: Edges have no direction (u ↔ v)

### By Weights

1. **Weighted Graph**: Edges have weights/costs
2. **Unweighted Graph**: All edges equal weight (usually 1)

### By Connectivity

1. **Connected Graph**: Path exists between every pair of vertices
2. **Disconnected Graph**: Some vertices unreachable
3. **Strongly Connected (Directed)**: Path exists in both directions
4. **Weakly Connected (Directed)**: Connected if treated as undirected

### Special Graphs

1. **Tree**: Connected acyclic graph (V-1 edges)
2. **DAG (Directed Acyclic Graph)**: No cycles
3. **Cyclic Graph**: Contains at least one cycle
4. **Complete Graph**: Every vertex connected to every other
5. **Bipartite Graph**: Vertices in two sets, edges only between sets

## 🔄 Core Graph Algorithms

### 1. Depth-First Search (DFS)

**Time**: O(V + E) | **Space**: O(V)

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    // Process node
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}
```

**When to use**:

- Finding connected components
- Cycle detection
- Topological sorting
- Path finding
- Backtracking problems

### 2. Breadth-First Search (BFS)

**Time**: O(V + E) | **Space**: O(V)

```cpp
void bfs(int start, vector<vector<int>>& adj) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        // Process node
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

**When to use**:

- Shortest path in unweighted graphs
- Level-order traversal
- Finding all nodes at distance K
- 0-1 BFS for special weighted graphs

### 3. Dijkstra's Algorithm

**Time**: O((V + E) log V) with priority queue

```cpp
vector<int> dijkstra(int src, vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src}); // {distance, node}

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, weight] : adj[u]) {
            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

**When to use**:

- Shortest path in weighted graphs (non-negative weights)
- Network routing
- GPS navigation

### 4. Bellman-Ford Algorithm

**Time**: O(V × E)

**When to use**:

- Shortest path with negative weights
- Detecting negative cycles

### 5. Floyd-Warshall Algorithm

**Time**: O(V³) | **Space**: O(V²)

**When to use**:

- All-pairs shortest path
- Dense graphs
- Detecting negative cycles

### 6. Topological Sort

**Only for DAGs** | **Time**: O(V + E)

**DFS-based**:

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }
    st.push(node); // Add to stack after all descendants
}
```

**Kahn's Algorithm (BFS-based)**:

```cpp
vector<int> topoSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++) {
        for(int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> result;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int neighbor : adj[node]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result.size() == n ? result : vector<int>{}; // Empty if cycle
}
```

**When to use**:

- Course scheduling
- Build systems
- Task dependencies

### 7. Union-Find (Disjoint Set Union)

**Time**: O(α(n)) ≈ O(1) per operation

```cpp
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;

        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
        return true;
    }
};
```

**When to use**:

- Connected components
- Kruskal's MST
- Cycle detection
- Dynamic connectivity

### 8. Minimum Spanning Tree

**Kruskal's Algorithm**: O(E log E)

```cpp
int kruskal(int n, vector<tuple<int,int,int>>& edges) {
    sort(edges.begin(), edges.end()); // Sort by weight
    DSU dsu(n);
    int cost = 0;

    for(auto [w, u, v] : edges) {
        if(dsu.unite(u, v)) {
            cost += w;
        }
    }
    return cost;
}
```

**Prim's Algorithm**: O((V + E) log V)

**When to use**:

- Network design (minimize cable length)
- Clustering algorithms
- Approximation algorithms

## 🎨 Common Patterns & Problem Types

### Pattern 1: Connected Components

**Problems**: Number of Islands, Number of Provinces

```cpp
int countComponents(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }
    return count;
}
```

### Pattern 2: Cycle Detection

**Undirected Graph (DFS)**:

```cpp
bool hasCycleDFS(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            if(hasCycleDFS(neighbor, node, adj, visited)) return true;
        } else if(neighbor != parent) {
            return true; // Back edge found
        }
    }
    return false;
}
```

**Directed Graph (DFS)**:

```cpp
bool hasCycleDFS(int node, vector<vector<int>>& adj, vector<int>& color) {
    color[node] = 1; // Gray (in progress)
    for(int neighbor : adj[node]) {
        if(color[neighbor] == 1) return true; // Back edge
        if(color[neighbor] == 0 && hasCycleDFS(neighbor, adj, color)) return true;
    }
    color[node] = 2; // Black (completed)
    return false;
}
```

### Pattern 3: Shortest Path

- **Unweighted**: BFS
- **Weighted (non-negative)**: Dijkstra
- **Weighted (negative allowed)**: Bellman-Ford
- **All pairs**: Floyd-Warshall
- **0-1 weights**: 0-1 BFS (deque)

### Pattern 4: Bipartite Check

```cpp
bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(int neighbor : adj[node]) {
                    if(color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if(color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
```

### Pattern 5: Grid/Matrix as Graph

```cpp
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(isValid(nx, ny, grid.size(), grid[0].size()) &&
           !visited[nx][ny] && grid[nx][ny] == 1) {
            dfs(nx, ny, grid, visited);
        }
    }
}
```

### Pattern 6: Multi-source BFS

**Problems**: Rotten Oranges, 01 Matrix

```cpp
void multiSourceBFS(vector<vector<int>>& grid) {
    queue<pair<int,int>> q;

    // Add all sources to queue
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == SOURCE) {
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        // Process neighbors
    }
}
```

### Pattern 7: Strongly Connected Components

**Kosaraju's Algorithm**: Two DFS passes
**Tarjan's Algorithm**: Single DFS with low-link values

## 📋 Common Problem Categories

### 1. Traversal Problems

- Number of Islands
- Flood Fill
- Clone Graph
- All Paths from Source to Target

### 2. Shortest Path Problems

- Shortest Path in Binary Matrix
- Network Delay Time
- Cheapest Flights Within K Stops
- Path with Maximum Probability

### 3. Cycle Detection Problems

- Course Schedule I & II
- Detect Cycle in Graph
- Find Eventual Safe States

### 4. Connectivity Problems

- Number of Provinces
- Redundant Connection
- Critical Connections in Network
- Accounts Merge

### 5. Topological Sort Problems

- Course Schedule
- Alien Dictionary
- Minimum Height Trees
- Parallel Courses

### 6. Bipartite Problems

- Is Graph Bipartite
- Possible Bipartition

### 7. Tree Problems (Special Graphs)

- Diameter of Tree
- Lowest Common Ancestor
- Serialize/Deserialize

### 8. Advanced Problems

- Traveling Salesman (NP-hard)
- Graph Coloring
- Maximum Flow (Ford-Fulkerson)
- Eulerian Path/Circuit

## 🧠 When to Use Which Approach

| Problem Type                     | Algorithm          | Time Complexity |
| -------------------------------- | ------------------ | --------------- |
| Explore all paths                | DFS                | O(V + E)        |
| Shortest path (unweighted)       | BFS                | O(V + E)        |
| Shortest path (weighted)         | Dijkstra           | O((V+E) log V)  |
| Shortest path (negative weights) | Bellman-Ford       | O(VE)           |
| All pairs shortest path          | Floyd-Warshall     | O(V³)          |
| Detect cycle                     | DFS/Union-Find     | O(V + E)        |
| Connected components             | DFS/BFS/Union-Find | O(V + E)        |
| Topological sort                 | DFS/Kahn's         | O(V + E)        |
| MST                              | Kruskal/Prim       | O(E log E)      |
| Bipartite check                  | BFS coloring       | O(V + E)        |

## 💡 Key Insights

1. **DFS vs BFS**:

   - DFS: Use recursion/stack, good for paths, cycles, backtracking
   - BFS: Use queue, good for shortest path, level-order
2. **Graph Representation**:

   - Adjacency list for sparse graphs (interviews)
   - Adjacency matrix for dense graphs or quick edge lookup
3. **Grid = Graph**: Treat 2D matrices as graphs with 4/8 directional movement
4. **Visited Array**: Essential to prevent infinite loops and duplicate work
5. **Time Complexity**: Usually O(V + E) for traversal algorithms
6. **Space Complexity**: O(V) for visited array, recursion stack
7. **Edge Cases**:

   - Disconnected components
   - Self-loops
   - Multiple edges
   - Empty graph
   - Single node

## 🎯 Interview Tips

1. **Clarify the problem**:

   - Directed or undirected?
   - Weighted or unweighted?
   - Can there be cycles?
   - Connected or disconnected?
2. **Choose representation**: Adjacency list for most problems
3. **Consider edge cases**: Empty graph, single node, disconnected components
4. **Optimize**: Use appropriate algorithm based on constraints
5. **Common mistakes**:

   - Forgetting to mark nodes as visited
   - Not handling disconnected components
   - Wrong parent tracking in cycle detection
   - Integer overflow in path costs

## 📚 Further Reading

- **Books**: "Introduction to Algorithms" (CLRS), "Algorithm Design Manual"
- **Practice Platforms**: LeetCode (Graph tag), Codeforces, HackerRank
- **Topics to explore**: Network Flow, Strongly Connected Components, Articulation Points, Bridge Detection

## 🔗 Disjoint Set Union (DSU) in Detail

Disjoint Set Union, also called Union-Find, is a data structure used to maintain multiple non-overlapping groups. It is built for problems where items keep getting connected, merged, or grouped.

It answers these questions quickly:

- 🧩 Which group does this element belong to?
- 🔄 Can these two groups be merged?
- ✅ Are these two elements already connected?
- 📦 How many connected groups/components are left?

Each set has one representative parent. `find(x)` returns the representative of `x`, and `unite(a, b)` merges the sets containing `a` and `b` if they are different.

### 💡 Core Idea

- Initially every node is its own parent.
- If two nodes are connected by an edge, merge their sets.
- Two nodes are in the same connected component if their representatives are equal.
- Path compression makes future `find` calls faster by directly attaching nodes to their root.
- Union by size or rank keeps the tree shallow.

### 🧠 When Your Mind Should Click DSU

Think of DSU when the problem has words like:

- "connected components"
- "same group"
- "merge"
- "union"
- "redundant connection"
- "number of provinces"
- "friend circles"
- "accounts merge"
- "minimum cost to connect"
- "is there a cycle in an undirected graph"
- "edges are added one by one"
- "are two nodes connected"
- "group equivalent values"

The mental trigger is simple:

> If the problem repeatedly connects two things and later asks about groups, components, or whether two things belong together, DSU should be considered first.

### ✅ When to Use DSU

Use DSU when the problem asks about connectivity after merging pairs of nodes.

- 🌐 Count connected components in an undirected graph
- 🔁 Detect a cycle in an undirected graph
- 🚫 Find redundant edges
- 🌉 Build Minimum Spanning Tree with Kruskal's algorithm
- 👥 Merge accounts, emails, names, cities, stones, or variables into groups
- 🧱 Merge adjacent cells in grid problems
- 📈 Track dynamic connectivity when edges are only added
- ❓ Answer whether two nodes belong to the same component
- ⚖️ Group equivalent values or equations

### 🧪 Common Problem Types

| Problem Type | DSU Signal | Example |
| --- | --- | --- |
| Connected components | Count groups after unions | Number of Provinces |
| Cycle detection | Edge connects nodes already in same set | Redundant Connection |
| Group merging | Same email/name/value means same group | Accounts Merge |
| Grid grouping | Adjacent valid cells belong together | Number of Islands II |
| MST | Pick cheapest edges without forming cycles | Kruskal's Algorithm |
| Equations/equality | `a == b` means merge, `a != b` means check conflict | Satisfiability of Equality Equations |
| Stones/removal | Same row or column means same group | Most Stones Removed |
| Dynamic connectivity | Connections are added over time | Online component count |

### ❌ When Not to Use DSU

DSU is not the right tool when the graph needs path order, distance, direction, or edge deletion support.

- Shortest path problems need BFS, Dijkstra, Bellman-Ford, or Floyd-Warshall.
- Directed cycle detection usually needs DFS or topological sorting.
- Path reconstruction needs traversal or parent tracking from BFS/DFS.
- Removing edges dynamically needs advanced structures or offline reverse processing.
- Problems needing all reachable nodes from a source are usually simpler with DFS/BFS.
- Problems asking for actual traversal order should not be solved only with DSU.

### 🧱 Implementation

```cpp
class DSU {
    vector<int> parent, size;

public:
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0); // every node starts as its own parent
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa == pb) return false; // already in the same component

        if(size[pa] < size[pb]) swap(pa, pb); // attach smaller tree under bigger tree
        parent[pb] = pa;
        size[pa] += size[pb];
        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int componentSize(int x) {
        return size[find(x)];
    }
};
```

### ⏱️ Time and Space Complexity

- `find`: Amortized O(alpha(n)), practically constant
- `unite`: Amortized O(alpha(n)), practically constant
- `same`: Amortized O(alpha(n)), practically constant
- Space: O(n)

`alpha(n)` is the inverse Ackermann function. For competitive programming constraints, it behaves like a very small constant.

### 🧩 Common DSU Patterns

#### Count Components

```cpp
int countComponents(int n, vector<pair<int,int>>& edges) {
    DSU dsu(n);
    int components = n;

    for(auto [u, v] : edges) {
        if(dsu.unite(u, v)) components--; // reduce only when two different groups merge
    }

    return components;
}
```

#### Detect Cycle in an Undirected Graph

```cpp
bool hasCycle(int n, vector<pair<int,int>>& edges) {
    DSU dsu(n);

    for(auto [u, v] : edges) {
        if(!dsu.unite(u, v)) return true; // same parent means this edge forms a cycle
    }

    return false;
}
```

#### Kruskal's Minimum Spanning Tree

```cpp
int minimumSpanningTree(int n, vector<tuple<int,int,int>>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int total = 0;

    for(auto [weight, u, v] : edges) {
        if(dsu.unite(u, v)) total += weight; // take edge only if it connects two components
    }

    return total;
}
```

### 🚦 DSU Decision Checklist

- Are pairs of nodes/items being connected or merged?
- Do I only need to know group membership, not the exact path?
- Is the graph undirected?
- Are edges added but not deleted?
- Do I need to count components after merges?
- Does adding an edge between already connected nodes indicate a cycle?
- Can strings, grid cells, rows, columns, or equations be converted into node ids?

If most answers are yes, DSU is probably a strong fit.

### 🛠️ Practical Tips

- Convert labels to `0...n-1` if nodes are strings or large values.
- Use `unite(a, b)` when an edge or equality connects two nodes.
- Use `same(a, b)` when checking if two nodes are already connected.
- Decrease component count only when `unite` returns `true`.
- In grid problems, map `(row, col)` to `row * cols + col`.
- For Kruskal's algorithm, sort edges by weight before calling `unite`.
- For email/name/group problems, use `unordered_map<string, int>` to assign ids.
