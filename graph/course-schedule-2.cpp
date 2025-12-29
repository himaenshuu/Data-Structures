#include <bits/stdc++.h>
using namespace std;
#include "../utilities.h"
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build Graph
        for (auto p : prerequisites)
        {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;

        // Queue for indegree = 0
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> order;
        // Bfs
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (int next : adj[course])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        if (order.size() != numCourses)
        {
            return {};
        }
        else
            return order;
    }
};
// T.c = O(V+E)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n = 2;
    vector<vector<int>> vect = {{1, 0}};
    print1darray(sol.findOrder(n, vect));

    return 0;
}