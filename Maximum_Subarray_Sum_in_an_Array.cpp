/*
================================================================================
LeetCode #53 - Maximum Subarray (Kadane's Algorithm)
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Google
- Facebook
- Apple
- Adobe
- Bloomberg
- LinkedIn
- Oracle
- Goldman Sachs
- Uber
- Salesforce

PROBLEM STATEMENT:
Given an integer array nums, find the contiguous subarray with the largest sum
and return its sum.

CONSTRAINTS:
- 1 <= nums.length <= 10^5
- -10^4 <= nums[i] <= 10^4

EXAMPLE 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: Subarray [4,-1,2,1] has the largest sum = 6

EXAMPLE 2:
Input: nums = [1]
Output: 1

EXAMPLE 3:
Input: nums = [5,4,-1,7,8]
Output: 23

APPROACH 1: Brute Force (maxvalue)
- Check all possible subarrays
- Time Complexity: O(n²)
- Space Complexity: O(1)

APPROACH 2: Kadane's Algorithm (maxvalue1) ⭐ OPTIMAL
- Key Insight: At each position, decide whether to EXTEND the current sum or START FRESH
- Compare: current_sum + arr[i] vs arr[i] alone
- Keep track of the maximum sum seen so far
- Time Complexity: O(n)
- Space Complexity: O(1)

KADANE'S ALGORITHM EXPLANATION:
At each position, we decide:
- Add current element to existing sum, OR
- Start fresh from current element (if previous sum was negative)
This greedy choice leads to optimal solution!

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
#define endl "\n"

int maxvalue(vector<int> &arr)
{
    int max = INT_MIN;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        int sum = arr[i];
        max = (sum > max) ? sum : max;
        for (int j = i + 1; j < size; j++)
        {
            sum += arr[j];
            if (sum > max)
                max = sum;
        }
    }

    return max > 0 ? max : 0;
}
// T.C = O(n^2) S.C = O(1)

// In previous one while adding we are carrying the negative sum too ,
// but kadane's algorithm says why to carry negative sum , if it
// do not contribute in the maximum sum .
// We will improve this part and make negative sum zero

int maxvalue1(vector<int> &arr)
{
    int max = INT_MIN;
    int size = arr.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (sum < max)
            sum = 0;
        max = (sum > max) ? sum : max;
    }

    return max > 0 ? max : 0;
}

// T.c = O(n) S.C = O(1)

int main()
{
    vi v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxvalue(v) << endl;
    return 0;
}

