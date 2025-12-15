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
