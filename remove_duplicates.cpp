/*
================================================================================
LeetCode #26 - Remove Duplicates from Sorted Array
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
- Oracle
- Goldman Sachs
- Uber

PROBLEM STATEMENT:
Given an integer array nums sorted in non-decreasing order, remove the
duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.

Return the number of unique elements in nums.

CONSTRAINTS:
- 1 <= nums.length <= 3 * 10^4
- -100 <= nums[i] <= 100
- nums is sorted in non-decreasing order
- Must modify array in-place with O(1) extra memory

EXAMPLE 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

EXAMPLE 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

APPROACH: Two-Pointer (In-Place)
- Use index pointer for position of unique elements
- Compare current element with previous
- If different, place at index position and increment index
- Time Complexity: O(n)
- Space Complexity: O(1)

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void remove_duplicates(vector<int> &vect)
{
    int n = vect.size(), index = 1;
    for (int i = 1; i < n; i++)
    {
        if (vect[i] != vect[i - 1])
        {
            vect[index] = vect[i];
            index++;
        }
    }
    vect.resize(index);

    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }
}
// Inplace algorithm
// T.c = O(n)
// S.c = O(1)

int main()
{
    vector<int> v = {0, 0, 1, 1, 2, 2, 3, 4, 4, 5, 6};
    remove_duplicates(v);

    return 0;
}