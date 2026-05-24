#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        long long ans = 0;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) ans += 1LL * (nums[i - 1] - nums[i]);
        }
        return ans;
    }
};
