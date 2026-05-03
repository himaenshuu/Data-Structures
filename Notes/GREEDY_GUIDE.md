# Greedy Algorithms - Complete Guide

## 📚 What is a Greedy Algorithm?

A **Greedy Algorithm** makes the locally optimal choice at each step with the hope of finding a global optimum. It never reconsiders its choices.

**Key Characteristics**:
- Makes a choice that looks best at the moment
- Never looks back (no backtracking)
- Hopes local optimum leads to global optimum
- Fast and efficient when applicable
- Doesn't always guarantee optimal solution

## 🎯 Greedy vs Other Approaches

| Approach | Strategy | Optimization | Backtracking |
|----------|----------|--------------|--------------|
| **Greedy** | Local optimal → Global optimal | May not be optimal | No |
| **Dynamic Programming** | Optimal substructure + overlapping | Always optimal | No |
| **Backtracking** | Try all possibilities | Optimal (if complete search) | Yes |
| **Divide & Conquer** | Break into subproblems | Depends | No |

## 🔑 When to Use Greedy

### Greedy Works When

1. **Greedy Choice Property**: Locally optimal choice leads to globally optimal solution
2. **Optimal Substructure**: Optimal solution contains optimal solutions to subproblems

### How to Verify Greedy Works

1. **Prove by contradiction**: Assume greedy doesn't give optimal, show contradiction
2. **Exchange argument**: Show any non-greedy solution can be converted to greedy without worsening
3. **Stay ahead argument**: Show greedy is always ahead of optimal at each step

## 🎨 Classic Greedy Patterns

### Pattern 1: Activity Selection / Interval Scheduling

**Problem**: Select maximum number of non-overlapping activities

**Strategy**: Sort by end time, select earliest ending activity that doesn't conflict

```cpp
struct Activity {
    int start, end;
};

int maxActivities(vector<Activity>& activities) {
    // Sort by end time
    sort(activities.begin(), activities.end(),
         [](Activity& a, Activity& b) { return a.end < b.end; });

    int count = 1;
    int lastEnd = activities[0].end;

    for(int i = 1; i < activities.size(); i++) {
        if(activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    return count;
}
```

**Time**: O(N log N) | **Space**: O(1)

**Similar Problems**:
- Meeting Rooms II
- Non-overlapping Intervals
- Minimum Number of Arrows to Burst Balloons

### Pattern 2: Fractional Knapsack

**Problem**: Maximize value with weight constraint (can take fractions)

**Strategy**: Sort by value/weight ratio, take items greedily

```cpp
struct Item {
    int value, weight;
    double ratio;

    Item(int v, int w) : value(v), weight(w), ratio((double)v/w) {}
};

double fractionalKnapsack(vector<Item>& items, int capacity) {
    // Sort by value/weight ratio (descending)
    sort(items.begin(), items.end(),
         [](Item& a, Item& b) { return a.ratio > b.ratio; });

    double totalValue = 0.0;

    for(Item& item : items) {
        if(capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }
    return totalValue;
}
```

**Time**: O(N log N) | **Space**: O(1)

**Note**: For 0/1 Knapsack (can't take fractions), use DP, not greedy!

### Pattern 3: Huffman Coding (Optimal Merge)

**Problem**: Build optimal binary tree for variable-length encoding

**Strategy**: Always merge two smallest frequency nodes

```cpp
struct Node {
    char character;
    int freq;
    Node *left, *right;

    Node(char c, int f) : character(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

Node* huffmanCoding(vector<pair<char, int>>& data) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create leaf nodes
    for(auto [ch, freq] : data) {
        minHeap.push(new Node(ch, freq));
    }

    // Build tree
    while(minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        minHeap.push(parent);
    }

    return minHeap.top();
}
```

**Time**: O(N log N) | **Space**: O(N)

**Similar Problems**:
- Minimum Cost to Connect Sticks
- Merge K Sorted Lists (similar pattern)

### Pattern 4: Minimum Spanning Tree

#### Kruskal's Algorithm
**Strategy**: Sort edges, add smallest edge that doesn't create cycle

```cpp
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
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

int kruskalMST(int n, vector<tuple<int, int, int>>& edges) {
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

**Time**: O(E log E) | **Space**: O(V)

#### Prim's Algorithm
**Strategy**: Grow MST by adding minimum weight edge from tree to non-tree vertices

```cpp
int primMST(int n, vector<vector<pair<int, int>>>& adj) {
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, 0}); // {weight, node}
    int cost = 0;

    while(!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if(inMST[u]) continue;
        inMST[u] = true;
        cost += w;

        for(auto [v, weight] : adj[u]) {
            if(!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }
    return cost;
}
```

**Time**: O((V + E) log V) | **Space**: O(V + E)

### Pattern 5: Dijkstra's Shortest Path

**Strategy**: Always expand shortest unvisited path

```cpp
vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

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

**Time**: O((V + E) log V) | **Space**: O(V)

**Why it's greedy**: Always chooses minimum distance vertex to explore

### Pattern 6: Job Scheduling with Deadlines

**Problem**: Maximize profit by scheduling jobs before deadlines

**Strategy**: Sort by profit, assign to latest available slot before deadline

```cpp
struct Job {
    int profit, deadline;
};

int maxProfit(vector<Job>& jobs) {
    // Sort by profit (descending)
    sort(jobs.begin(), jobs.end(),
         [](Job& a, Job& b) { return a.profit > b.profit; });

    int maxDeadline = 0;
    for(Job& j : jobs) {
        maxDeadline = max(maxDeadline, j.deadline);
    }

    vector<int> slots(maxDeadline + 1, -1);
    int totalProfit = 0;

    for(Job& job : jobs) {
        // Find latest available slot
        for(int t = job.deadline; t > 0; t--) {
            if(slots[t] == -1) {
                slots[t] = job.profit;
                totalProfit += job.profit;
                break;
            }
        }
    }
    return totalProfit;
}
```

**Time**: O(N² log N) | **Space**: O(N)

### Pattern 7: Coin Change (Greedy - Not Always Optimal!)

**Problem**: Minimum coins to make amount

**Greedy Strategy**: Always pick largest coin ≤ remaining amount

```cpp
int minCoins(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend()); // Descending order
    int count = 0;

    for(int coin : coins) {
        count += amount / coin;
        amount %= coin;
    }

    return amount == 0 ? count : -1;
}
```

**⚠️ Warning**: Only works for canonical coin systems (like US coins: 1, 5, 10, 25)
**Counter-example**: coins = [1, 3, 4], amount = 6
- Greedy: 4 + 1 + 1 = 3 coins
- Optimal: 3 + 3 = 2 coins

**Use DP for general coin change!**

### Pattern 8: Gas Station (Circular Tour)

**Problem**: Find starting station to complete circular tour

**Strategy**: Track cumulative gas, start from point where it becomes negative

```cpp
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalTank = 0, currTank = 0, start = 0;

    for(int i = 0; i < gas.size(); i++) {
        totalTank += gas[i] - cost[i];
        currTank += gas[i] - cost[i];

        if(currTank < 0) {
            start = i + 1;
            currTank = 0;
        }
    }

    return totalTank >= 0 ? start : -1;
}
```

**Time**: O(N) | **Space**: O(1)

**Why it works**: If total gas ≥ total cost, solution exists. If we can't reach station i from start, we also can't reach i from any station before start.

### Pattern 9: Jump Game

**Problem**: Can reach last index with given jump lengths?

**Strategy**: Track maximum reachable position

```cpp
bool canJump(vector<int>& nums) {
    int maxReach = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
        if(maxReach >= nums.size() - 1) return true;
    }
    return true;
}
```

**Time**: O(N) | **Space**: O(1)

**Minimum Jumps**:
```cpp
int minJumps(vector<int>& nums) {
    int jumps = 0, currentEnd = 0, farthest = 0;

    for(int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);

        if(i == currentEnd) {
            jumps++;
            currentEnd = farthest;

            if(currentEnd >= nums.size() - 1) break;
        }
    }
    return jumps;
}
```

### Pattern 10: Partition Labels

**Problem**: Partition string into as many parts as possible so each letter appears in at most one part

**Strategy**: Track last occurrence of each character, extend partition when needed

```cpp
vector<int> partitionLabels(string s) {
    vector<int> lastIndex(26);
    for(int i = 0; i < s.length(); i++) {
        lastIndex[s[i] - 'a'] = i;
    }

    vector<int> result;
    int start = 0, end = 0;

    for(int i = 0; i < s.length(); i++) {
        end = max(end, lastIndex[s[i] - 'a']);

        if(i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return result;
}
```

**Time**: O(N) | **Space**: O(1)

## 📋 Common Greedy Problem Categories

### 1. Scheduling Problems
- Activity Selection
- Meeting Rooms
- Task Scheduler
- Job Sequencing

### 2. Interval Problems
- Merge Intervals
- Insert Interval
- Non-overlapping Intervals
- Minimum Arrows to Burst Balloons

### 3. Array/String Problems
- Jump Game I & II
- Gas Station
- Candy Distribution
- Partition Labels

### 4. Graph Problems
- Minimum Spanning Tree (Kruskal, Prim)
- Dijkstra's Shortest Path
- Topological Sort (Kahn's)

### 5. Optimization Problems
- Fractional Knapsack
- Huffman Coding
- Optimal Merge Pattern
- Egyptian Fraction

### 6. Number Theory
- Minimum Coins (canonical systems)
- Maximize Product
- Container With Most Water

## 💡 Greedy Strategy Decision Tree

```
Can I make a locally optimal choice?
│
├─ Yes → Does it lead to global optimum?
│   │
│   ├─ Yes → Use Greedy ✓
│   │
│   └─ No → Consider DP or Backtracking
│
└─ No → Not a greedy problem
```

## 🧠 Proving Greedy Correctness

### Method 1: Exchange Argument

Show that any optimal solution can be transformed into greedy solution without worsening

**Example** (Activity Selection):
- Assume optimal solution O doesn't pick earliest ending activity
- Replace first activity in O with earliest ending
- Still valid and no worse → Greedy is optimal

### Method 2: Stay Ahead

Show greedy solution is always at least as good as optimal at each step

**Example** (Fractional Knapsack):
- After selecting items, greedy has at least as much value as any other solution
- Can't do better by different choices

### Method 3: Contradiction

Assume greedy doesn't give optimal, derive contradiction

## 🎯 When Greedy Fails

### Common Pitfalls

1. **0/1 Knapsack**: Need DP, not greedy
2. **General Coin Change**: Greedy fails for non-canonical systems
3. **Longest Path**: Greedy fails, need DP or exhaustive search
4. **Subset Sum**: Greedy fails, need DP
5. **Traveling Salesman**: Greedy gives approximation, not optimal

### Why Greedy Fails

- No optimal substructure
- Local optimum ≠ global optimum
- Previous choices affect later ones
- Need to consider all possibilities

## 📊 Greedy vs DP

| Aspect | Greedy | Dynamic Programming |
|--------|--------|---------------------|
| Choice | Irrevocable | Considers all options |
| Guarantee | Not always optimal | Always optimal |
| Speed | Usually faster | Usually slower |
| Memory | Usually less | Usually more |
| Examples | Activity selection | 0/1 Knapsack |

**When to switch from Greedy to DP**:
- Greedy gives wrong answer on test cases
- Can't prove greedy correctness
- Problem has overlapping subproblems

## 🔧 Common Greedy Techniques

### 1. Sorting
Most greedy algorithms start with sorting
```cpp
sort(items.begin(), items.end(), comparator);
```

### 2. Priority Queue
For continuously selecting min/max
```cpp
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
```

### 3. Two Pointers
Often combined with greedy
```cpp
int left = 0, right = n - 1;
while(left < right) { ... }
```

### 4. Hash Map
Track state for greedy decisions
```cpp
unordered_map<char, int> lastIndex;
```

## 💻 Template for Greedy Problems

```cpp
// 1. Understand the problem
// 2. Identify if greedy works (prove it!)
// 3. Define greedy choice
// 4. Implement

// Generic structure:
int greedySolution(vector<int>& input) {
    // Step 1: Preprocessing (often sorting)
    sort(input.begin(), input.end(), comparator);

    // Step 2: Initialize result
    int result = 0;

    // Step 3: Make greedy choices
    for(int item : input) {
        if(isValidChoice(item)) {
            result += makeChoice(item);
        }
    }

    return result;
}
```

## 🎓 Interview Tips

### How to Identify Greedy

1. **Keywords**: "minimum", "maximum", "optimal", "earliest", "latest"
2. **Pattern**: Making sequential choices
3. **Constraint**: Can't go back and change previous choices
4. **Hint**: O(N log N) expected complexity (sorting)

### During Interview

1. **Clarify constraints**: Does greedy guarantee optimality here?
2. **Prove correctness**: Explain why greedy works
3. **Find counterexample**: If you think greedy might fail
4. **Start simple**: Explain greedy idea before coding
5. **Consider alternatives**: Mention DP if greedy seems iffy

### Common Mistakes

1. Assuming greedy always works
2. Not proving correctness
3. Wrong sorting criteria
4. Off-by-one errors in intervals
5. Forgetting edge cases

## 📚 Famous Greedy Algorithms

1. **Huffman Coding** - Data compression
2. **Dijkstra's Algorithm** - Shortest path
3. **Kruskal's Algorithm** - Minimum spanning tree
4. **Prim's Algorithm** - Minimum spanning tree
5. **Fractional Knapsack** - Resource allocation
6. **Activity Selection** - Scheduling
7. **Job Sequencing** - Deadline scheduling
8. **Prim's Algorithm** - Network design

## 🔗 Real-World Applications

- **CPU Scheduling**: Shortest job first
- **Network Routing**: Dijkstra's algorithm
- **Data Compression**: Huffman coding
- **File Merging**: Optimal merge pattern
- **Job Scheduling**: Deadline-based scheduling
- **Resource Allocation**: Load balancing
- **Coin Change**: Making change (US coins)
- **Traffic Optimization**: Traffic light timing

## Summary Table

| Problem | Greedy Strategy | Time | Works? |
|---------|----------------|------|--------|
| Activity Selection | Earliest end time | O(N log N) | ✓ Yes |
| Fractional Knapsack | Max value/weight | O(N log N) | ✓ Yes |
| 0/1 Knapsack | Max value/weight | O(N log N) | ✗ No - Use DP |
| Dijkstra's | Min distance | O((V+E)log V) | ✓ Yes |
| Coin Change (canonical) | Largest coin | O(N) | ✓ Yes |
| Coin Change (general) | Largest coin | O(N) | ✗ No - Use DP |
| MST (Kruskal) | Min weight edge | O(E log E) | ✓ Yes |
| Job Scheduling | Max profit | O(N² log N) | ✓ Yes |

**Remember**: Greedy is powerful but requires proof. When in doubt, verify with examples or use DP!
