/*
Problem: Jump Game (LeetCode #55)
Difficulty: Medium
Top Companies: Amazon, Google, Meta, Microsoft, Apple
Entry-Level Importance (0-2 YoE): 4/5

Early Intuition:
Greedily track the farthest index you can reach as you scan left to right.
If at any point your current index exceeds the farthest reachable index, you
are stuck. If the farthest reachable index reaches or passes the last index
before you get stuck, return true.
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int mi = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > mi)
                return false;
            else
            {
                mi = max(mi, i + nums[i]);
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}