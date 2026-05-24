/******************************************************************************
 * GRAPH ALGORITHM TEMPLATE
 ******************************************************************************/
/*
 * Algorithm: Shortest Path in Directed Acyclic Graph (DAG) - Weighted
 * Category: Shortest Path / Topological Sorting
 *
 * DESCRIPTION:
 * Efficient algorithm for finding shortest paths in weighted DAGs. First
 * perform topological sort to get processing order, then relax edges in
 * that order. Works in O(V+E) time unlike Dijkstra's O((V+E)logV). The
 * topological order ensures each node is processed before all nodes that
 * depend on it, so each edge is relaxed exactly once.
 *
 * KEY CHARACTERISTICS:
 * - Only works on Directed Acyclic Graphs (DAGs)
 * - More efficient than Dijkstra for DAGs: O(V+E) vs O((V+E)logV)
 * - Uses topological sort + edge relaxation
 * - Can handle negative edge weights (unlike Dijkstra)
 * - Process nodes in topological order guarantees optimal paths
 *
 * COMPLEXITY:
 * Time: O(V + E) - Topological sort O(V+E) + relaxation O(E)
 * Space: O(V) - Distance array + visited array + stack
 *
 * COMMON USE CASES:
 * 1. Critical path analysis in project scheduling (PERT/CPM)
 * 2. Longest path in DAG (negate weights)
 * 3. Dynamic programming on DAGs
 * 4. Course prerequisite chains with costs
 * 5. Game level progression with weighted transitions
 *
 * RELATED LEETCODE PROBLEMS:
 * - LC 1334 (Find City With Smallest Number of Neighbors) - Medium
 * - LC 787 (Cheapest Flights Within K Stops) - Medium
 * - LC 1203 (Sort Items by Groups) - Hard
 * - LC 2050 (Parallel Courses III) - Hard
 * - LC 1976 (Number of Ways to Arrive) - Medium
 *
 * INTERVIEW IMPORTANCE:
 * Rating: 4/5 - Important for weighted DAG problems
 *
 * IMPLEMENTATION NOTES:
 * - Step 1: Topological sort using DFS to get processing order
 * - Step 2: Initialize distances to infinity, source to 0
 * - Step 3: Process nodes in topological order, relax outgoing edges
 * - Edge relaxation: if dist[u] + weight(u,v) < dist[v], update dist[v]
 * - Can handle negative weights (DAG ensures no negative cycles)
 * - For general graphs with weights, use Dijkstra or Bellman-Ford
 *
 * DATE CREATED: 2026-03-23
 * LAST UPDATED: 2026-03-23
 ******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    void topoDfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;

        for (auto &edge : adj[node]) // edges corresponds to the edge of the graph
        {
            int next = edge.first;
            if (!vis[next])
            {
                topoDfs(next, adj, vis, st);
            }
        }
        st.push(node);
    }

    vector<int> shortestPathDAG(int v, vector<vector<pair<int, int>>> &adj, int src)
    {
        // topsort
        vector<int> vis(v, 0);
        stack<int> st;

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                topoDfs(i, adj, vis, st);
            }
        }

        // initialize the distance array
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;

        // relaxation in topo-order
        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            if (dist[u] != INT_MAX)
            {
                for (auto &edge : adj[u])
                {
                    int v = edge.first;
                    int wt = edge.second;
                    if (dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Optional: convert unreachable nodes to -1
        for (int i = 0; i < v; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v = 6;
    vector<vector<pair<int, int>>> adj(v);

    // Edges: (destination, weight)
    vector<tuple<int, int, int>> edges = {{0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {4, 2, 2}, {4, 5, 4}, {2, 3, 1}, {5, 3, 1}};
    for (auto &e : edges)
        adj[get<0>(e)].push_back({get<1>(e), get<2>(e)});

    Solution sol;
    int src = 0;
    vector<int> dist = sol.shortestPathDAG(v, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < v; i++)
        cout << "Node " << i << ": " << dist[i] << "\n";

    return 0;
}