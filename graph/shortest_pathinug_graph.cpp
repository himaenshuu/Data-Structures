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