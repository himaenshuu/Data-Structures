/******************************************************************************
 * GRAPH ALGORITHM TEMPLATE
 ******************************************************************************/
/*
 * Algorithm: Depth-First Search (DFS) - Iterative Implementation
 * Category: Graph Traversal
 *
 * DESCRIPTION:
 * DFS explores a graph by going as deep as possible along each branch before
 * backtracking. The iterative version uses an explicit stack to replicate
 * recursive behavior. Preferred when dealing with very deep graphs to avoid
 * stack overflow, or when you need more control over the traversal state.
 *
 * KEY CHARACTERISTICS:
 * - Uses explicit stack data structure (LIFO)
 * - Avoids recursion stack overflow for deep graphs
 * - More verbose but same logic as recursive DFS
 * - Easier to convert to iterative deepening or custom traversals
 * - Neighbors pushed in reverse order to maintain left-to-right order
 *
 * COMPLEXITY:
 * Time: O(V + E) - Visit each vertex once, explore each edge once
 * Space: O(V) - Visited array + explicit stack in worst case
 *
 * COMMON USE CASES:
 * 1. Finding connected components when recursion depth is a concern
 * 2. Detecting cycles in graphs with unknown depth
 * 3. Path finding in very deep or large graphs
 * 4. Tree/graph traversal where stack overflow is possible
 * 5. Custom DFS variations requiring state management
 *
 * RELATED LEETCODE PROBLEMS:
 * - LC 200 (Number of Islands) - Medium
 * - LC 547 (Number of Provinces) - Medium
 * - LC 733 (Flood Fill) - Easy
 * - LC 841 (Keys and Rooms) - Medium
 * - LC 1466 (Reorder Routes) - Medium
 *
 * INTERVIEW IMPORTANCE:
 * Rating: 4/5 - Highly Recommended
 *
 * IMPLEMENTATION NOTES:
 * - Mark node as visited when popping from stack (not when pushing)
 * - Push neighbors in reverse order to maintain DFS left-to-right order
 * - Alternative: mark visited when pushing (prevents duplicate stack entries)
 * - No stack overflow risk unlike recursive DFS
 * - Easier to pause/resume or add custom state tracking
 *
 * DATE CREATED: 2026-03-23
 * LAST UPDATED: 2026-03-23
 ******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5};
    graph[3] = {};
    graph[4] = {5};
    graph[5] = {};

    vector<bool> visited(n, false);
    stack<int> st;

    st.push(0); // start node

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            visited[node] = true;
            cout << node << " ";
        }

        // push neighbours in reverse order to maintain DFS order
        for (int i = graph[node].size() - 1; i >= 0; --i)
        {
            int neighbour = graph[node][i];
            if (!visited[neighbour])
            {
                st.push(neighbour);
            }
        }
    }
}

/*
When DFS is useful

• Detecting cycles
• Connected components
• Solving mazes
• Topological sorting
• Path finding in trees
• Backtracking problems (N-Queens, Sudoku solver)

DFS is conceptually simple but extremely powerful in algorithm design.
*/
