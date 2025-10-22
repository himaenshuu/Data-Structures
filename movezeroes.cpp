/*
================================================================================
LeetCode #283 - Move Zeroes
================================================================================

DIFFICULTY: Easy ⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Facebook
- Google
- Apple
- Bloomberg
- Adobe
- Uber
- Goldman Sachs

PROBLEM STATEMENT:
Given an integer array nums, move all 0's to the end while maintaining the
relative order of non-zero elements. Must do this in-place without making
a copy of the array.

CONSTRAINTS:
- 1 <= nums.length <= 10^4
- -2^31 <= nums[i] <= 2^31 - 1

EXAMPLE 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

EXAMPLE 2:
Input: nums = [0]
Output: [0]

APPROACH 1: Extra Space (moveZeros)
- Store non-zero elements in new array
- Append zeros at end
- Time: O(n), Space: O(n)

APPROACH 2: Two-Pointer (moveZeros1) ⭐ OPTIMAL
- Find first zero position (j)
- Swap non-zero elements with position j
- Time: O(n), Space: O(1)

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> moveZeros(int n, vector<int> a)
{
    // Write your code here.
    vector<int> b;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            b.push_back(a[i]);
        else
            cnt++;
    }

    while (cnt--)
        b.push_back(0);

    return b;
}

// more Optimal approach

vector<int> moveZeros1(int n, vector<int> a)
{
    // Write your code here.
    int j = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return a;

    for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

int main()
{
    vector<int> v = {1, 0, 3, 4, 5, 0, 5, 0, 7};
    vector<int> v1 = moveZeros1(9, v);

    for (auto &el : v1)
    {
        cout << el << " ";
    }

    return 0;
}