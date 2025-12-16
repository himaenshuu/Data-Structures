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