/******************************************************************************
 * LEETCODE PROBLEM
 ******************************************************************************/
/*
 * Problem: 547. Number of Provinces
 * Difficulty: Medium
 * LeetCode Link: https://leetcode.com/problems/number-of-provinces/
 *
 * PROBLEM STATEMENT:
 * Given an n x n matrix isConnected where isConnected[i][j] = 1 if the i-th
 * city and j-th city are directly connected, and isConnected[i][j] = 0
 * otherwise. Return the total number of provinces (connected components).
 * A province is a group of directly or indirectly connected cities.
 * Constraints: 1 <= n <= 200.
 *
 * Example:
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2 (two provinces: {0,1} and {2})
 *
 * APPROACH:
 * Algorithm: Depth-First Search (DFS)
 * Strategy: Treat the problem as finding connected components in a graph.
 *           For each unvisited city, run DFS to mark all cities in that
 *           province as visited, then increment the province count.
 *
 * COMPLEXITY ANALYSIS:
 * Time Complexity: O(n²) - Check all matrix entries during DFS traversal
 * Space Complexity: O(n) - Visited array + recursion stack depth
 *
 * COMPANIES (Asked in interviews):
 * Tier 1 (FAANG+): Amazon, Google, Microsoft, Meta, Apple
 * Tier 2 (Tech): Bloomberg, Oracle, Adobe, Uber, Salesforce, LinkedIn
 *
 * ENTRY LEVEL IMPORTANCE:
 * Rating: 5/5 - Essential
 * Why: Core graph connectivity problem using DFS. Tests understanding of
 *      connected components and graph traversal. Common in entry-level
 *      interviews as a fundamental graph problem.
 *
 * SIMILAR PROBLEMS: LC 200, LC 323, LC 684, LC 990, LC 1319
 *
 * DATE SOLVED: 2026-03-23
 * LAST REVIEWED: 2026-03-23
 ******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
/*
We preferred dfs in this case because dfs enable us to search & visit in deep for each node.
*/
class Solution
{
private:
    void dfs(int node, vector<vector<int>> &isconnected, vector<bool> &visited)
    {
        visited[node] = true;
        int n = isconnected.size();

        for (int i = 0; i < n; i++)
        {
            if (isconnected[node][i] == 1 && !visited[i])
            {
                dfs(i, isconnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    vector<vector<int>> v1 = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}};

    Solution obj;
    cout << "Number of provinces are =" << obj.findCircleNum(v);
    return 0;
}