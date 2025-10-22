/*
================================================================================
LeetCode #169 - Majority Element (Moore's Voting Algorithm)
================================================================================

DIFFICULTY: Easy ⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Google
- Facebook
- Apple
- Adobe
- Bloomberg
- Uber
- Oracle
- Goldman Sachs
- Airbnb

PROBLEM STATEMENT:
Given an array nums of size n, return the majority element. The majority
element is the element that appears more than ⌊n/2⌋ times.

You may assume that the majority element always exists in the array.

CONSTRAINTS:
- n == nums.length
- 1 <= n <= 5 * 10^4
- -10^9 <= nums[i] <= 10^9

EXAMPLE 1:
Input: nums = [3,2,3]
Output: 3

EXAMPLE 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

MOORE'S VOTING ALGORITHM:
- Maintain a candidate and count
- If count == 0, set new candidate
- If current element == candidate, increment count
- Else decrement count
- Candidate at end is majority element

WHY IT WORKS:
Since majority element appears > n/2 times, it will always survive the
cancellation process with other elements.

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

This is the optimal solution for finding majority element!

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int findmajority(vector<int> &vect)
{
    int count = 0, el = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (count == 0)
        {
            count++;
            el = vect[i];
        }
        else
        {
            if (vect[i] != el)
            {
                count--;
            }
            else
                count++;
        }
    }

    return el;
}

int main()
{
    vector<int> v = {1, 2, 2, 3, 2, 4, 2};

    int num = findmajority(v);

    cout << num << endl;
    return 0;
}
