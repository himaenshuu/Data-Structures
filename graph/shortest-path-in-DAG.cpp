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