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