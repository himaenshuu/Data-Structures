/*
================================================================================
LeetCode #27 - Remove Element
================================================================================

DIFFICULTY: Easy ⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Facebook
- Google
- Apple
- Adobe
- Bloomberg
- Uber

PROBLEM STATEMENT:
Given an integer array nums and an integer val, remove all occurrences of val
in nums in-place. The order of the elements may be changed. Return the number
of elements in nums which are not equal to val.

CONSTRAINTS:
- 0 <= nums.length <= 100
- 0 <= nums[i] <= 50
- 0 <= val <= 100
- Must modify array in-place with O(1) extra memory

EXAMPLE 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Remove all occurrences of 3

EXAMPLE 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,3,0,4,_,_,_]

APPROACH: Two-Pointer Method
- Use index pointer to track position for non-target elements
- Iterate through array and copy non-target elements to index position
- Resize array to remove extra elements
- Time Complexity: O(n)
- Space Complexity: O(1)

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> remove_target(vector<int> &nums, int target)
{
    int n = nums.size();
    auto it = find(nums.begin(), nums.end(), target); // t.c = o(n)
    int index = -1;

    if (it != nums.end())
        index = distance(nums.begin(), it);

    if (index == -1)
        return nums;

    for (int i = index; i < n; i++)
    {
        if (nums[i] != nums[index])
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return nums;
}

// above code works for sorted vector  , early stage logic

vector<int> remove_target1(vector<int> &nums, int target)
{
    int n = nums.size();
    int index = 0;

    for (int i = 0; i < n; i++) // T.C = O(n)
    {
        if (nums[i] != target)
        {
            nums[index] = nums[i];
            index++;
        }
    }
    nums.resize(index); // remove elements from index to end
    return nums;
}

// it works for all

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int t;
    cin >> t;

    vector<int> v1 = remove_target1(v, t);

    for (auto el : v1)
    {
        cout << el << " " << endl;
    }

    return 0;
}
