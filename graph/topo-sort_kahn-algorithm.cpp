#include <bits/stdc++.h>
using namespace std;
#include "../utilities.h"
typedef long long ll;
#define endl "\n"
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> indegree(V, 0);
        // calculate indegree
        for (int i = 0; i < V; i++)
        {
            for (int it : edges[i])
            {
                indegree[it]++;
            }
        }
        // push nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        // remove indegree of neighbour
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neighbour : edges[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        // check cycle
        if (topo.size() < V)
            return {};

        return topo;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Example 1: Simple linear graph
    cout << "Example 1 - Linear graph (0->1->2->3):\n";
    int V1 = 4;
    vector<vector<int>> v1(V1);
    v1[0] = {1};
    v1[1] = {2};
    v1[2] = {3};
    v1[3] = {};
    print1darray(sol.topoSort(V1, v1));

    // Example 2: More complex DAG
    cout << "\nExample 2 - Complex DAG:\n";
    int V2 = 6;
    vector<vector<int>> v2(V2);
    v2[0] = {2, 3}; // 0 -> 2, 3
    v2[1] = {3};    // 1 -> 3
    v2[2] = {4};    // 2 -> 4
    v2[3] = {4, 5}; // 3 -> 4, 5
    v2[4] = {5};    // 4 -> 5
    v2[5] = {};     // 5 has no outgoing edges
    print1darray(sol.topoSort(V2, v2));

    // Example 3: Another DAG - Course prerequisites
    cout << "\nExample 3 - Course prerequisites (5->4->3, 5->2->3->1->0):\n";
    int V3 = 6;
    vector<vector<int>> v3(V3);
    v3[5] = {4, 2}; // 5 -> 4, 2
    v3[4] = {3};    // 4 -> 3
    v3[2] = {3};    // 2 -> 3
    v3[3] = {1};    // 3 -> 1
    v3[1] = {0};    // 1 -> 0
    v3[0] = {};     // 0 has no outgoing edges
    print1darray(sol.topoSort(V3, v3));

    return 0;
}

// Note:- The answer is printing one of the topo order only, it can be many.
// We follow same approach for the problem: Cycle detection in directed graph