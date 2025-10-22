/*
================================================================================
LeetCode #1 - Two Sum
================================================================================

DIFFICULTY: Easy ⭐

COMPANIES ASKED:
- Amazon
- Google
- Facebook
- Microsoft
- Apple
- Adobe
- Bloomberg
- Uber
- Goldman Sachs
- Airbnb
- Oracle
- Salesforce

PROBLEM STATEMENT:
Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may
not use the same element twice.

You can return the answer in any order.

CONSTRAINTS:
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists.

EXAMPLE 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] == 9, so return [0, 1].

EXAMPLE 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

APPROACH: Hash Map
- Use an unordered_map to store value -> index mapping
- For each element, check if (target - current) exists in map
- Time Complexity: O(n)
- Space Complexity: O(n)

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        vector<int> nums;
        for (int i = 0; i < size; i++)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        int target;
        cin >> target;

        unordered_map<int, int> unmap;
        for (int i = 0; i < size; i++)
        {
            unmap[nums[i]] = i;
        }

        for (int i = 0; i < size; i++)
        {
            int complement = target - nums[i];
            if (unmap.count(complement))
            {
                cout << i << " " << unmap[complement] << endl;
                break;
            }
        }
    }
}
