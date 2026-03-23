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
    cout << sol.longestArithmetic(nums) << '\n';
    return 0;
}
