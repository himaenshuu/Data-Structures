/*
Problem: 3Sum (LeetCode #15)
Difficulty: Medium
Top Companies: Amazon, Google, Meta, Microsoft, Apple
Entry-Level Importance (0-2 YoE): 4/5

Problem Statement:
Given an integer array nums, return all triplets [nums[i], nums[j], nums[k]]
such that i != j != k and nums[i] + nums[j] + nums[k] == 0. The solution set
must not contain duplicate triplets.

Early Intuition:
Sort the array first. Fix one element with an outer loop, then use two
pointers on the remaining subarray to find pairs that sum to its negative.
Move left pointer right when sum is too small, right pointer left when too
large. Skip duplicates at both the outer and inner level to avoid repeat triplets.

Optimal Approach:
Sort -> outer loop fixes nums[i] -> two pointers left=i+1, right=n-1.
if sum < 0: left++; if sum > 0: right--; if sum == 0: record and skip duplicates.
Time: O(n^2), Space: O(1) extra.
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> nums) // tc = O(n^2 logn) & sc = O(n^2)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = i;
        }

        set<vector<int>> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int comp = -(nums[i] + nums[j]);
                if (mp.find(comp) != mp.end())
                {
                    int k = mp[comp];
                    if (k != i && k != j)
                    {
                        vector<int> temp = {nums[i], nums[j], comp};
                        sort(temp.begin(), temp.end()); // O(logn)
                        s.insert(temp);
                    }
                }
            }
        }
        return vector<vector<int>>(s.begin(), s.end());
    }

    vector<vector<int>> threeSum1(vector<int> nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1, k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0)
                    j++;
                else
                {
                    if (sum > 0)
                    {
                        k--;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1])
                        {
                            j++;
                        }
                        while (j < k && nums[k] == nums[k + 1])
                        {
                            k--;
                        }
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> vect = {-2, 0, 1, 1, 2};

    print2darray(sol.threeSum(vect));
    cout << "" << endl;

    return 0;
}