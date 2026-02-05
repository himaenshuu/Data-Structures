/*
================================================================================
LeetCode #2149 - Rearrange Array Elements by Sign
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Google
- Adobe
- Samsung
- Oracle

PROBLEM STATEMENT:
Rearrange elements by sign such that they occur in an alternate order.
Given an array with equal number of positive and negative integers, rearrange
the array such that positive and negative numbers alternate.

CONSTRAINTS:
- Array has equal number of positive and negative elements
- First element should be positive
- Maintain relative order of positive and negative numbers

EXAMPLE:
Input: [1, -2, -3, 4]
Output: [1, -2, 4, -3]
Explanation: Positive numbers at even indices, negative at odd indices

APPROACH: Two-Pass Method
- First pass: Place all positive numbers at even indices (0, 2, 4...)
- Second pass: Place all negative numbers at odd indices (1, 3, 5...)
- Time Complexity: O(n)
- Space Complexity: O(n) for result array

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> rearrange(const vector<int> &vect)
{
    int size = vect.size();
    vector<int> v(size, 0);
    int k = 0;

    for (int i = 0; i < size; i++)
    {
        if (vect[i] > 0)
        {
            v[k] = vect[i];
            k = k + 2;
        }
    }
    k = 1;
    for (int i = 0; i < size; i++)
    {
        if (vect[i] < 0)
        {
            v[k] = vect[i];
            k = k + 2;
        }
    }

    return v;
}

int main()
{
    vector<int> v = rearrange({1, -2, -3, 4});

    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
