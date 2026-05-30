/******************************************************************************
 * LEETCODE PROBLEM
 ******************************************************************************/
/*
 * Problem: 210. Course Schedule II
 * Difficulty: Medium
 * LeetCode Link: https://leetcode.com/problems/course-schedule-ii/
 *
 * PROBLEM STATEMENT:
 * Given numCourses and a list of prerequisite pairs [a,b] where you must
 * take course b before course a, return the ordering of courses you should
 * take to finish all courses. If there are multiple valid answers, return
 * any of them. If it's impossible to finish all courses, return empty array.
 * Constraints: 1 <= numCourses <= 2000, 0 <= prerequisites.length <= 5000.
 *
 * Example:
 * Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,2,1,3] or [0,1,2,3] (both valid)
 *
 * APPROACH:
 * This problem can be solved by finding a topological order of a directed
 * graph. Each edge goes from prerequisite course to dependent course.
 *
 * Approach 1: Topological Sort using Kahn's Algorithm (BFS)
 * Strategy: Build directed graph with indegree array. Process courses with
 *           indegree 0, add them to result order, and decrement indegrees
 *           of neighbors. If all courses are added to result, return order;
 *           otherwise return empty array because a cycle exists.
 *
 * Approach 2: DFS Topological Sort
 * Strategy: Build directed graph from prerequisite to course. Use a visited
 *           state array where 0 means unvisited, 1 means currently in the DFS
 *           path, and 2 means fully processed. If DFS reaches a node with
 *           state 1, a cycle exists, so return an empty array. Otherwise,
 *           push each course into order after all dependent courses are
 *           processed, then reverse the order to get a valid course sequence.
 *
 * COMPLEXITY ANALYSIS:
 * Time Complexity: O(V + E) - Visit all vertices and edges once
 * Space Complexity: O(V + E) - Adjacency list + indegree array + queue
 *
 * COMPANIES (Asked in interviews):
 * Tier 1 (FAANG+): Amazon, Google, Microsoft, Meta, Apple
 * Tier 2 (Tech): Bloomberg, Oracle, Adobe, Uber, LinkedIn, Salesforce
 *
 * ENTRY LEVEL IMPORTANCE:
 * Rating: 4/5 - Highly Recommended
 * Why: Direct follow-up to Course Schedule I. Tests topological sort
 *      implementation with output requirement. Common in interviews as it
 *      combines cycle detection with order generation. Important for
 *      understanding dependency resolution in real systems.
 *
 * SIMILAR PROBLEMS: LC 207, LC 802, LC 1136, LC 2115, LC 269
 *
 * DATE SOLVED: 2026-03-23
 * LAST REVIEWED: 2026-03-23
 ******************************************************************************/

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

    bool dfs(int course, vector<vector<int>> &adj, vector<int> &visited, vector<int> &order)
    {
        if (visited[course] == 1)
        {
            return false;
        }
        if (visited[course] == 2)
        {
            return true;
        }

        visited[course] = 1;

        for (int next : adj[course])
        {
            if (!dfs(next, adj, visited, order))
            {
                return false;
            }
        }

        visited[course] = 2;
        order.push_back(course);
        return true;
    }

    vector<int> findOrder2(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> order;

        // Build graph from prerequisite course to dependent course
        for (auto p : prerequisites)
        {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
        }

        // 0 = not visited, 1 = current DFS path, 2 = fully processed
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0 && !dfs(i, adj, visited, order))
            {
                return {};
            }
        }

        reverse(order.begin(), order.end()); 
        // we have reversed it because dfs is recursive and uses LIFO technique. 
        // It pushed the first started course in the last order
        /*
        dfs(0)
         dfs(1)
          push 1
         push 0
        */
        return order;
    }
};
// T.c = O(V+E)
// findOrder2 T.c = O(V+E), S.c = O(V+E)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n = 2;
    vector<vector<int>> vect = {{1, 0}};
    print1darray(sol.findOrder2(n, vect));

    return 0;
}
