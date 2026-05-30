/******************************************************************************
 * LEETCODE PROBLEM
 ******************************************************************************/
/*
 * Problem: 207. Course Schedule
 * Difficulty: Medium
 * LeetCode Link: https://leetcode.com/problems/course-schedule/
 *
 * PROBLEM STATEMENT:
 * Given numCourses and a list of prerequisite pairs [a,b] where you must
 * take course b before course a, determine if it's possible to finish all
 * courses. Return true if you can complete all courses, false otherwise.
 * Essentially, detect if there's a cycle in the directed graph.
 * Constraints: 1 <= numCourses <= 2000, 0 <= prerequisites.length <= 5000.
 *
 * Example:
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true (take course 0 first, then course 1)
 *
 * APPROACH:
 * This problem can be solved by detecting a cycle in a directed graph.
 *
 * Approach 1: Topological Sort using Kahn's Algorithm (BFS)
 * Strategy: Build directed graph with indegree array. Add all courses with
 *           indegree 0 to queue. Process courses, decrement indegrees of
 *           neighbors. If all courses are processed, no cycle exists.
 *
 * Approach 2: DFS Cycle Detection
 * Strategy: Build directed graph from prerequisite to course. Use a visited
 *           state array where 0 means unvisited, 1 means currently in the DFS
 *           path, and 2 means fully processed. If DFS reaches a node with
 *           state 1, a cycle exists, so all courses cannot be completed.
 *           If every node is processed without finding a cycle, return true.
 *
 * COMPLEXITY ANALYSIS:
 * Time Complexity: O(V + E) - Visit all vertices and edges once
 * Space Complexity: O(V + E) - Adjacency list + indegree array + queue
 *
 * COMPANIES (Asked in interviews):
 * Tier 1 (FAANG+): Amazon, Google, Microsoft, Meta, Apple
 * Tier 2 (Tech): Bloomberg, Oracle, Adobe, Salesforce, Uber, LinkedIn
 *
 * ENTRY LEVEL IMPORTANCE:
 * Rating: 5/5 - Essential
 * Why: Fundamental topological sort and cycle detection problem. Tests
 *      understanding of directed graphs and prerequisite dependencies.
 *      Extremely common in entry-level interviews (appears in 60%+ of
 *      graph interviews). Building block for many real-world problems.
 *
 * SIMILAR PROBLEMS: LC 210, LC 802, LC 1136, LC 2392, LC 269
 *
 * DATE SOLVED: 2026-03-23
 * LAST REVIEWED: 2026-03-23
 ******************************************************************************/

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

    bool dfs(int course, vector<vector<int>> &adj, vector<int> &visited)
    {
        if (visited[course] == 1)
        {
            return false; 
        }
        if (visited[course] == 2)
        {
            return true; // means loop found, we have reached same node again
        }

        visited[course] = 1;

        for (int next : adj[course])
        {
            if (!dfs(next, adj, visited))
            {
                return false;
            }
        }

        visited[course] = 2;
        return true;
    }

    bool canFinish2(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses); //adjacency matrix
        vector<int> visited(numCourses, 0);//courses is starting from 0 so we took so

        // Build graph from; prerequisite course to dependent course
        for (auto p : prerequisites)
        {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
        }

        // 0 = not visited, 1 = current DFS path, 2 = fully processed
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0 && !dfs(i, adj, visited)) // if a node is visited skip it
            {
                return false;
            }
        }

        return true;
    }
};
// T.c = O(V+E)
// canFinish2 T.c = O(V+E), S.c = O(V+E)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n = 2;
    vector<vector<int>> vect = {{1, 0}};
    if (sol.canFinish2(n, vect) == true)
    {
        cout << "True" << endl;
    }
    else
        cout << "False" << endl;
    cout << "" << endl;

    return 0;
}
