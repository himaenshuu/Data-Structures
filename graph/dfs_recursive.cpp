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

    // creating a sample graph
    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5};
    graph[3] = {};
    graph[4] = {5};
    graph[5] = {};

    dfs(0); // start DFS from node 0
}
