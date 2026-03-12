/*
Problem: Find Repeating and Missing Number
Difficulty: Medium
Top Companies: Amazon, Microsoft, Samsung, Flipkart
Entry-Level Importance (0-2 YoE): 3/5

Early Intuition:
For an array of size n containing values [1..n] with one duplicate and one
missing number, a frequency map makes it trivial: count each value, then scan
for the count that is 2 (duplicate) and the count that is 0 (missing). An
alternative math approach uses the diff between expected and actual sum/sum-of-squares.
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    // using map and stl functions
    vector<int> findNum(vector<int> &nums)
    {
        int n = nums.size();
        int missing = -1;
        int repeating = -1;
        unordered_map<int, int>
            mp;
        for (int i = 0; i < n; i++) // O(N)
        {
            if (!mp.count(nums[i]))
            {
                mp[nums[i]]++;
            }
            else
                repeating = nums[i]; // repeating
        }

        for (int i = 1; i <= n; i++) // O(N)
        {
            if (mp.count(i)) // O(1)
            {
                continue;
            }
            else
                missing = i; // repeating
        }

        return {repeating, missing};
    }

    // using math
    vector<int> findNum1(vector<int> &nums)
    {
        long long size = nums.size();
        long long expectedSum = size * (size + 1) / 2;
        long long expectedSquareSum = size * (size + 1) * (2 * size + 1) / 6;

        long long actualSum = 0;
        long long actualSquareSum = 0;
        for (int number : nums)
        {
            actualSum += number;
            actualSquareSum += 1LL * number * number;
        }

        long long sumDifference = actualSum - expectedSum; // repeating - missing
        long long squareSumDifference = actualSquareSum - expectedSquareSum;
        long long sumOfRepeatingAndMissing = squareSumDifference / sumDifference;

        long long repeating = (sumDifference + sumOfRepeatingAndMissing) / 2;
        long long missing = sumOfRepeatingAndMissing - repeating;

        return {(int)repeating, (int)missing};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vect = {1, 2, 3, 4, 5, 5};
    Solution sol;
    vector<int> v = sol.findNum(vect);
    cout << "ans is :" << v[0] << " and " << v[1] << endl;

    return 0;
}