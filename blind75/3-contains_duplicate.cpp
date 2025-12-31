#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums) //O(nlogn)
    {
        sort(nums.begin(), nums.end()); // O(nlogn) bcoz of binary insertion
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i + 1] == nums[i])
                return true;
        }
        return false;
    }

    bool containsDuplicate1(vector<int> &nums) //O(n)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if(mp.count(nums[i])){
                return true;
            }
            mp[nums[i]]++;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> vect = {5, 2, 1, 4};
    if(sol.containsDuplicate1(vect)){
        cout << "True" << endl;
    }
    else
        cout << "False" << endl;

    return 0;
}