#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#include "utilities.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp; 
        for (int i = 0; i < nums.size(); i++) 
        {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int comp = target - nums[i];
            if (mp.find(comp) != mp.end())
            {
                return {i, mp[comp]};
            }
        }
        return {};
    }
};
// t.c = O(n)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;
    Solution sol;
    vector<int> v = {2, 3, 4, 5};
    int target = 6;

    print1darray(sol.twoSum(v, target));
    return 0;
}
