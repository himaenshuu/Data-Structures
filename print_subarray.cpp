/*
================================================================================
Print Maximum Sum Subarray
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Google
- Facebook
- Adobe

PROBLEM STATEMENT:
Find and print the contiguous subarray within an array which has the largest sum.

CONSTRAINTS:
- Array can contain both positive and negative numbers
- At least one positive number should exist (or return empty array)

EXAMPLE:
Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: [4, -1, 2, 1]
Explanation: Subarray [4, -1, 2, 1] has maximum sum = 6
 
APPROACH 1: Brute Force (printsubarray)
- Check all possible subarrays
- Track subarray with maximum sum
- Time Complexity: O(n²)
- Space Complexity: O(n) for storing subarray

APPROACH 2: Optimized (subarraySum)
- Calculate only maximum sum (not subarray itself)
- Time Complexity: O(n²)
- Space Complexity: O(1)

NOTE: For O(n) solution, use Kadane's Algorithm (see Maximum_Subarray_Sum_in_an_Array.cpp)

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> printsubarray(vector<int> &vect)
{
    int n = vect.size();

    int max = INT_MIN;
    int sum = 0;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        vector<int> v1;
        for (int j = i; j < n; j++)
        {
            v1.push_back(vect[j]);
            sum += vect[j];
            if (sum > max)
            {
                v = v1;
                max = sum;
            }
        }
    }
    return v;
}

int subarraySum(vector<int> &vect)
{
    int n = vect.size();

    int max = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += vect[j];
            if (sum > max)
                max = sum;
        }

        // max = (sum > max) ? sum : max;
    }
    return max;
}

int main()
{
    int size;
    cin >> size;
    vector<int> vect(size);

    for (int i = 0; i < size; i++)
    {
        cin >> vect[i];
    }

    vector<int> v = printsubarray(vect);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
