#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        // use the cost vector to store minimum cost to reach at a stair
        for (int i = 2; i < n; i++)
        {
            cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
        }

        // bcoz we can reach top either from n-1 or n-2
        return min(cost[n - 1], cost[n - 2]);
    }
};

//tc=O(N)
//sc=O(1)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}