#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> b(2 * n);
        for (int i = 0; i < n; ++i) {
            b[i] = nums[i];
            b[i + n] = nums[n - 1 - i];
        }
        return b;
    }
};