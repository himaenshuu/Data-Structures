/******************************************************************************
 * GRAPH ALGORITHM TEMPLATE
 ******************************************************************************/
/*
 * Algorithm: Breadth-First Search (BFS)
 * Category: Graph Traversal / Shortest Path
 *
 * DESCRIPTION:
 * BFS explores a graph level by level, visiting all neighbors at distance k
 * before visiting neighbors at distance k+1. Uses a queue (FIFO) to maintain
 * traversal order. Guarantees shortest path in unweighted graphs and is
 * essential for level-order traversal and distance calculations.
 *
 * KEY CHARACTERISTICS:
 * - Uses queue data structure (FIFO)
 * - Explores nodes level by level (breadth-wise)
 * - Guarantees shortest path in unweighted graphs
 * - Mark nodes as visited when adding to queue (not when processing)
 * - Naturally suited for finding minimum distance/steps problems
 *
 * COMPLEXITY:
 * Time: O(V + E) - Visit each vertex once, explore each edge once
 * Space: O(V) - Visited array + queue holding vertices at current level
 *
 * COMMON USE CASES:
 * 1. Shortest path in unweighted graphs
 * 2. Level-order traversal of trees/graphs
 * 3. Finding connected components
 * 4. Minimum steps/operations problems (knight moves, word ladder)
 * 5. Social network analysis (degrees of separation)
 * 6. Multi-source BFS (rotting oranges, 01 matrix)
 *
 * RELATED LEETCODE PROBLEMS:
 * - LC 102 (Binary Tree Level Order) - Medium
 * - LC 107 (Binary Tree Level Order II) - Medium
 * - LC 994 (Rotting Oranges) - Medium
 * - LC 542 (01 Matrix) - Medium
 * - LC 127 (Word Ladder) - Hard
 *
 * INTERVIEW IMPORTANCE:
 * Rating: 5/5 - Fundamental building block for graph problems
 *
 * IMPLEMENTATION NOTES:
 * - Always mark node as visited WHEN ADDING to queue (prevents duplicates)
 * - For level tracking, process all nodes at current level before next
 * - Multi-source BFS: add all starting nodes to queue initially
 * - BFS finds shortest unweighted path; for weighted use Dijkstra
 * - Queue size at each iteration = nodes at current distance/level
 *
 * DATE CREATED: 2026-03-23
 * LAST UPDATED: 2026-03-23
 ******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs(int start)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbour : graph[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main()
{
    int n = 6; // nodes from 0 to 5
    graph.resize(n);
    visited.assign(n, false);

    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5};
    graph[3] = {};
    graph[4] = {5};
    graph[5] = {};

    bfs(0);
}

/*
Use Cases-
BFS is the correct tool when you need:

Shortest path in an unweighted graph
Levels of a graph or tree
Checking connectivity

Solving problems like:
Knight moves on a chessboard
Minimum operations to reach X from Y
Social network “degrees of separation”
*/