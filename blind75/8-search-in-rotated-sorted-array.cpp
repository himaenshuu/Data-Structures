#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target && nums[left] <= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (target == nums[left])
            return left;
        if (target == nums[right])
            return right;
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    int t = 0;
    Solution sol;
    cout << sol.search(v, t) << endl;

    return 0;
}