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
    cout << "" << endl;

    return 0;
}