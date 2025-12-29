#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
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

        int completed = 0;

        // Bfs
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            completed++;

            for (int next : adj[course])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        return completed == numCourses;
    }
};
//T.c = O(V+E)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n = 2;
    vector<vector<int>> vect = {{1, 0}};
    if (sol.canFinish(n, vect)==true)
    {
        cout << "True" << endl;
    }
    else
        cout << "False" << endl;
    cout << "" << endl;

    return 0;
}