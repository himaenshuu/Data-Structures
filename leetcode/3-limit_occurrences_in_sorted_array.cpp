#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        if (k <= 0) return {};

        int j = 0;
        for (int x : nums) {
            if (j < k || nums[j - k] != x) nums[j++] = x;
        }

        nums.resize(j);
        return nums;
    }
};
