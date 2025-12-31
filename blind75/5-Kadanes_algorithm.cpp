#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maximum = INT_MIN;
        int size = nums.size();
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum = max(nums[i], nums[i] + sum);
            maximum = max(maximum, sum);
        }
        return maximum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vect = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    cout << sol.maxSubArray(vect);

    return 0;
}