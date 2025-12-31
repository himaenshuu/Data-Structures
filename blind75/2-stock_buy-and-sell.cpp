#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int pr = (prices[i] - prices[i - 1]);
            if (pr > 0)
            {
                max = max + pr;
            }
        }
        return max;
    }
};
//Greedy approach works here 
//tc=O(n)


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vect = {7, 2, 5, 9};
    Solution sol;
    cout << sol.maxProfit(vect);

    return 0;
}