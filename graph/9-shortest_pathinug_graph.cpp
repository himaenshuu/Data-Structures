/******************************************************************************
 * GRAPH ALGORITHM TEMPLATE
 ******************************************************************************/
/*
 * Algorithm: Shortest Path in Unweighted Graph using BFS
 * Category: Shortest Path / Graph Traversal
 *
 * DESCRIPTION:
 * BFS naturally finds shortest paths in unweighted graphs because it explores
 * nodes level by level. The first time a node is reached is guaranteed to be
 * via the shortest path from source. This implementation calculates distances
 * to all nodes from a single source. Works for both directed and undirected
 * graphs. For weighted graphs, use Dijkstra's algorithm instead.
 *
 * KEY CHARACTERISTICS:
 * - Uses BFS (queue-based, FIFO)
 * - Only works for unweighted graphs (or all edge weights = 1)
 * - Finds shortest distance from single source to all reachable nodes
 * - Distance array doubles as visited tracking (-1 = unvisited)
 * - Returns -1 for unreachable nodes
 *
 * COMPLEXITY:
 * Time: O(V + E) - BFS visits each vertex and edge once
 * Space: O(V) - Distance array + queue
 *
 * COMMON USE CASES:
 * 1. Finding shortest path in grid/maze problems
 * 2. Minimum steps/moves problems (knight on chessboard)
 * 3. Social network distance (degrees of separation)
 * 4. Minimum transformations (word ladder)
 * 5. Level-based problems where all edges have equal cost
 *
 * RELATED LEETCODE PROBLEMS:
 * - LC 127 (Word Ladder) - Hard
 * - LC 286 (Walls and Gates) - Medium
 * - LC 1091 (Shortest Path in Binary Matrix) - Medium
 * - LC 847 (Shortest Path Visiting All Nodes) - Hard
 * - LC 863 (All Nodes Distance K) - Medium
 *
 * INTERVIEW IMPORTANCE:
 * Rating: 5/5 - Fundamental shortest path technique for unweighted graphs
 *
 * IMPLEMENTATION NOTES:
 * - Initialize distance array with -1 (infinity/unvisited)
 * - Set source distance to 0
 * - When visiting neighbor, set dist[neighbor] = dist[node] + 1
 * - Check if neighbor is unvisited (dist == -1) before processing
 * - For weighted graphs, use Dijkstra's algorithm instead
 * - For DAG with weights, use topological sort + relaxation
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
    vector<int> shortestPath(int v, vector<vector<int>> &adj, int src)
    {
        vector<int> dist(v, -1);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node])
            {
                if (dist[neighbour] == -1)
                {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }

        return dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v = 6;
    vector<vector<int>> adj(v);

    // Add edges (undirected)
    vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    for (auto &e : edges)
    {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    int src = 0;
    Solution sol;
    vector<int> result = sol.shortestPath(v, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < v; i++)
        cout << "Node " << i << ": " << result[i] << "\n";

    return 0;
}