/*
Problem (LeetCode-style, paraphrased):
Given an m x n grid of characters and a string `word`, determine if `word` can be formed by sequentially adjacent cells (up/down/left/right). Each cell may be used at most once in the path.

Difficulty: Medium

Companies (commonly reported; varies by source/time):
Amazon, Microsoft, Google, Meta, Apple, Uber, Bloomberg, LinkedIn, Salesforce, ByteDance

Entry-level importance: High

Optimal approach used here:
- Backtracking DFS from every cell; when a character matches, mark it as visited (temporary overwrite), explore 4 directions, then restore (backtrack).

Time complexity: O(m*n*4^L) worst-case, where L = |word|
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
private:
    bool dfs(vector<vector<char>> &board, string word, int i, int j,
             int index)
    {
        if (index == word.size())
            return true;
        // check the boundaries
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[index])
            return false;

        // Now we assum we have found the word , now mark it visited
        char temp = board[i][j];
        board[i][j] = '#';
        // explore the all directions
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);

        // backtarck and restore the value
        board[i][j] = temp;
        return found;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        // iterate through each cells and call dfs
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };

    // Test case 1
    {
        auto b = board;
        assert(sol.exist(b, "ABCCED") == true);
    }

    // Test case 2
    {
        auto b = board;
        assert(sol.exist(b, "ABCB") == false);
    }

    cout << "All tests passed." << endl;

    return 0;
}