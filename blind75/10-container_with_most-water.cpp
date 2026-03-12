/*
Problem: Container With Most Water (LeetCode #11)
Difficulty: Medium
Top Companies: Amazon, Google, Meta, Microsoft, Bloomberg
Entry-Level Importance (0-2 YoE): 4/5

Early Intuition:
Place two pointers at both ends. Area = min(height[left], height[right]) * width.
Moving the taller pointer inward can never improve the area (width shrinks and
height is still capped by the shorter line). Always move the shorter pointer
inward hoping to find a taller boundary that compensates for the lost width.
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

// two pointer approach
// t.c = O(n)

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        int sum = 0;

        while (i < j)
        {
            int area = min(height[i], height[j]) * (j - i);
            sum = (area > sum) ? area : sum;

            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vect = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution sol;

    cout << sol.maxArea(vect)<< endl;

    return 0;
}