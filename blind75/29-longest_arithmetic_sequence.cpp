/*
Problem (paraphrased, interview-style):
Given an integer array `nums`, find the maximum length of a contiguous subarray that forms an arithmetic progression (constant difference between adjacent elements) if you are allowed to modify at most one element of the array.

Difficulty: Medium (variant)

Companies (commonly reported; varies by source/time):
Google, Amazon, Meta, Microsoft, Apple, Uber, Bloomberg, LinkedIn, Salesforce, Adobe

Entry-level importance: Medium

Optimal approach used here:
- Build two DP arrays over contiguous runs: `left[i]` = length of arithmetic run ending at i, `right[i]` = length starting at i.
- Try (1) extending a run by changing one endpoint element and (2) bridging a left-run and right-run by changing the middle element when the span allows an integer midpoint difference.

Time complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestArithmetic(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 2)
            return n;
        // initialize right and left dp and initialize it with 1
        vector<int> left(n, 1), right(n, 1);

        // build left dp
        left[1] = 2;
        for (int i = 2; i < n; i++)
        {
            int d1 = nums[i - 1] - nums[i - 2];
            int d2 = nums[i] - nums[i - 1];

            left[i] = (d1 == d2) ? left[i - 1] + 1 : 2;
        }

        // build right dp
        right[n - 2] = 2;
        for (int i = n - 3; i >= 0; i--)
        {
            int d1 = nums[i + 2] - nums[i + 1];
            int d2 = nums[i + 1] - nums[i];

            right[i] = (d1 == d2) ? right[i + 1] + 1 : 2;
        }

        // build the ans from checking all the left subarray
        int ans = 2; // minimum possible

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, left[i]);
        }

        // Change one endpoint of an existing arithmetic run.
        // Try changing one element just after a left-run to extend it by 1.
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, left[i] + 1);
        }

        // Try changing one element just before a right-run to extend it by 1.
        for (int i = n - 1; i >= 1; i--)
        {
            ans = max(ans, right[i] + 1);
        }

        // Change one middle element and bridge both sides with same diff.
        // Try each index i as the single changed middle element.

        for (int i = 1; i < n - 1; i++)
        {

            int span = nums[i + 1] - nums[i - 1];
            if (span & 1)
                continue;

            int cd = span / 2; // this is how cd is calculated

            int leftlen = 1;
            if (i >= 2 && nums[i - 1] - nums[i - 2] == cd)
            {
                leftlen = left[i - 1];
            }

            int rightlen = 1;
            if (i <= n - 3 && nums[i + 2] - nums[i + 1] == cd)
            {
                rightlen = right[i + 1];
            }

            // now merge the two
            ans = max(ans, leftlen + 1 + rightlen);
        }
        ans = min(ans, n); // this is for the safety so that answer does not exceed the n
        return ans;
    }
};

int main()
{
    // Fast I/O setup.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Test case 1
    {
        vector<int> nums = {1, 2, 3, 4};
        assert(sol.longestArithmetic(nums) == 4);
    }

    // Test case 2
    {
        vector<int> nums = {1, 2, 3, 8, 9};
        assert(sol.longestArithmetic(nums) == 4);
    }

    cout << "All tests passed.\n";
    return 0;
}
