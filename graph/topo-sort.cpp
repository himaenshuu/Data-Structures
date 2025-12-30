#include <bits/stdc++.h>
using namespace std;
#include "../utilities.h"
typedef long long ll;
#define endl "\n"

// dfs approach
class Solution
{
public:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &edges)
    {
        vis[node] = 1;
        for (auto it : edges[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, st, edges);
            }
        }
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, edges);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
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
