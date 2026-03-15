#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArithmeticSubarrayAfterOneChange(vector<int>& nums) {
        const int n = (int)nums.size();
        if (n <= 2) return n;

        vector<int> left(n, 1), right(n, 1);

        left[1] = 2;
        for (int i = 2; i < n; i++) {
            long long d1 = 1LL * nums[i] - nums[i - 1];
            long long d2 = 1LL * nums[i - 1] - nums[i - 2];
            left[i] = (d1 == d2) ? left[i - 1] + 1 : 2;
        }

        right[n - 2] = 2;
        for (int i = n - 3; i >= 0; i--) {
            long long d1 = 1LL * nums[i + 1] - nums[i];
            long long d2 = 1LL * nums[i + 2] - nums[i + 1];
            right[i] = (d1 == d2) ? right[i + 1] + 1 : 2;
        }

        int ans = 2;
        for (int i = 0; i < n; i++) ans = max(ans, left[i]);

        // Change one endpoint of an existing arithmetic run.
        for (int i = 0; i < n - 1; i++) ans = max(ans, left[i] + 1);
        for (int i = 1; i < n; i++) ans = max(ans, right[i] + 1);

        // Change one middle element and bridge both sides with same diff.
        for (int i = 1; i + 1 < n; i++) {
            long long span = 1LL * nums[i + 1] - nums[i - 1];
            if (span & 1LL) continue;
            long long d = span / 2;

            int leftLen = 1;
            if (i - 1 >= 1 && 1LL * nums[i - 1] - nums[i - 2] == d) {
                leftLen = left[i - 1];
            }

            int rightLen = 1;
            if (i + 1 <= n - 2 && 1LL * nums[i + 2] - nums[i + 1] == d) {
                rightLen = right[i + 1];
            }

            ans = max(ans, leftLen + 1 + rightLen);
        }

        return min(ans, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.maxArithmeticSubarrayAfterOneChange(nums) << '\n';
    return 0;
}
