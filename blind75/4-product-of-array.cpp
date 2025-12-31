// product of array except self problem no - 238

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums) // tc=O(n)
    {
        int p = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            p = p * nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = p / nums[i];
        }

        return nums;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> vect = {2, 3, 4, 5};
    print1darray(sol.productExceptSelf(vect));
    cout << "" << endl;
    return 0;
}