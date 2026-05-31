/******************************************************************************
 * GRAPH ALGORITHM TEMPLATE
 ******************************************************************************/
/*
 * Algorithm: Depth-First Search (DFS) - Recursive Implementation
 * Category: Graph Traversal
 *
 * DESCRIPTION:
 * DFS explores a graph by going as deep as possible along each branch before
 * backtracking. The recursive version uses the call stack implicitly to
 * track the traversal path. Ideal for problems requiring complete path
 * exploration, connectivity checks, and cycle detection.
 *
 * KEY CHARACTERISTICS:
 * - Uses implicit recursion stack (call stack)
 * - LIFO order: explores deeply before backtracking
 * - Simpler to implement than iterative version
 * - Good for: connected components, cycle detection, path finding
 * - May cause stack overflow on very deep graphs (>10^4 depth)
 *
 * COMPLEXITY:
 * Time: O(V + E) - Visit each vertex once, explore each edge once
 * Space: O(V) - Visited array O(V) + recursion stack O(H) where H is height
 *
 * COMMON USE CASES:
 * 1. Finding connected components in undirected graphs
 * 2. Detecting cycles in directed/undirected graphs
 * 3. Topological sorting (with modifications)
 * 4. Path existence between two nodes
 * 5. Solving maze/island problems (LC 200, LC 733)
 *
 * RELATED LEETCODE PROBLEMS:
 * - LC 200 (Number of Islands) - Medium
 * - LC 547 (Number of Provinces) - Medium
 * - LC 733 (Flood Fill) - Easy
 * - LC 695 (Max Area of Island) - Medium
 * - LC 130 (Surrounded Regions) - Medium
 *
 * INTERVIEW IMPORTANCE:
 * Rating: 5/5 - Fundamental building block for graph problems
 *
 * IMPLEMENTATION NOTES:
 * - Always mark node as visited BEFORE recursing to avoid infinite loops
 * - For large/deep graphs, prefer iterative DFS to avoid stack overflow
 * - Can modify to track paths, detect cycles, or compute properties
 * - Works on both directed and undirected graphs (adjust neighbor logic)
 *
 * DATE CREATED: 2026-03-23
 * LAST UPDATED: 2026-03-23
 ******************************************************************************/

// using recursion

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph; // adjacency list
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    cout << node << " "; // process the node

    for (int neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour);
        }
    }
}

int main()
{
    int n = 6; // number of nodes (0 to 5)
    graph.resize(n);
    visited.assign(n, false);

    // creating a sample graph : adjacency list
    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5};
    graph[3] = {};
    graph[4] = {5};
    graph[5] = {};

    dfs(0); // start DFS from node 0
}
