#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

// Logic track both minprod and maxproduct
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                swap(maxprod, minprod);
            }
            minprod = min(nums[i], minprod * nums[i]); // extend it or stop
            maxprod = max(nums[i], maxprod * nums[i]);
            ans = max(ans, maxprod);
        }
        return ans;
    }
};
// tc = O(n)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> v = {3, -1, 4};
    cout << sol.maxProduct(v);

    return 0;
}