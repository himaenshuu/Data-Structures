#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArithmeticSubarrayAfterOneChange(vector<int> &nums)
    {
        // n = size of input array.
        const int n = (int)nums.size();
        // Arrays of size 0, 1, 2 are always arithmetic as-is.
        if (n <= 2)
            return n;

        // left[i] = length of longest arithmetic subarray ending at index i.
        // right[i] = length of longest arithmetic subarray starting at index i.
        vector<int> left(n, 1), right(n, 1);

        // Base case: first two elements form arithmetic subarray of length 2.
        left[1] = 2;
        // Build left[] from left to right.
        for (int i = 2; i < n; i++)
        {
            // d1 = difference between current pair (i-1, i).
            int d1 = nums[i] - nums[i - 1];
            // d2 = difference between previous pair (i-2, i-1).
            int d2 = nums[i - 1] - nums[i - 2];
            // If both diffs match, extend previous arithmetic run; otherwise start new run of length 2.
            left[i] = (d1 == d2) ? left[i - 1] + 1 : 2;
        }

        // Base case from right side: last two elements form arithmetic subarray of length 2.
        right[n - 2] = 2;
        // Build right[] from right to left.
        for (int i = n - 3; i >= 0; i--)
        {
            // d1 = difference between current pair (i, i+1).
            long long d1 = 1LL * nums[i + 1] - nums[i];
            // d2 = difference between next pair (i+1, i+2).
            long long d2 = 1LL * nums[i + 2] - nums[i + 1];
            // If both diffs match, extend arithmetic run to the left; otherwise start new run of length 2.
            right[i] = (d1 == d2) ? right[i + 1] + 1 : 2;
        }

        // ans stores the best (maximum) arithmetic subarray length found so far.
        int ans = 2;
        // Consider existing arithmetic runs without changing any element.
        for (int i = 0; i < n; i++)
            ans = max(ans, left[i]);

        // Change one endpoint of an existing arithmetic run.
        // Try changing one element just after a left-run to extend it by 1.
        for (int i = 0; i < n - 1; i++)
            ans = max(ans, left[i] + 1);

        // Try changing one element just before a right-run to extend it by 1.
        for (int i = 1; i < n; i++)
            ans = max(ans, right[i] + 1);

        // Change one middle element and bridge both sides with same diff.
        // Try each index i as the single changed middle element.
        for (int i = 1; i < n - 1; i++)
        {
            // span = nums[i+1] - nums[i-1]; for valid middle, span must be even (2*d).
            long long span = 1LL * nums[i + 1] - nums[i - 1];
            if (span & 1LL)
                continue;
            // Required common difference after changing nums[i].
            long long d = span / 2; // this is how cd is calculated

            // leftLen = arithmetic length that can connect from left side to i (default only nums[i-1]).
            int leftLen = 1;
            if (i >= 2 && nums[i - 1] - nums[i - 2] == d)
            {
                leftLen = left[i - 1];
            }

            // rightLen = arithmetic length that can connect from right side to i (default only nums[i+1]).
            int rightLen = 1;
            if (i <= n - 3 && nums[i + 2] - nums[i + 1] == d)
            {
                rightLen = right[i + 1];
            }

            // Total bridged length = left part + changed middle + right part.
            ans = max(ans, leftLen + 1 + rightLen);
        }

        // Safety clamp: answer cannot exceed n.
        return min(ans, n);
    }
};

int main()
{
    // Fast I/O setup.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // n = number of elements.
    int n;
    cin >> n;
    // nums = input array.
    vector<int> nums(n);
    // Read all elements.
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    // Create solution object.
    Solution sol;
    // Compute and print final answer.
    cout << sol.maxArithmeticSubarrayAfterOneChange(nums) << '\n';
    return 0;
}
