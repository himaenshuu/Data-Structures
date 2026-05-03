#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> score(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int e = 0, o = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] & 1)
                ans[i] = e;
            else
                ans[i] = o;

            if (nums[i] & 1)
                ++o;
            else
                ++e;
        }

        return ans;
    }
};
