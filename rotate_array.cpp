/*
================================================================================
LeetCode #189 - Rotate Array
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
- eBay
- Uber

PROBLEM STATEMENT:
Given an integer array nums, rotate the array to the right by k steps,
where k is non-negative.

Constraints:
- 1 <= nums.length <= 10^5
- -2^31 <= nums[i] <= 2^31 - 1
- 0 <= k <= 10^5

EXAMPLE 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation: Rotate 1 step to the right: [7,1,2,3,4,5,6]
             Rotate 2 steps to the right: [6,7,1,2,3,4,5]
             Rotate 3 steps to the right: [5,6,7,1,2,3,4]

EXAMPLE 2:
Input: nums = [100,1], k = 1
Output: [1,100]

EXAMPLE 3:
Input: nums = [-1], k = 3
Output: [-1]

OPTIMAL APPROACH: Reversal Algorithm (Best Space Complexity)
Step 1: Normalize k (k = k % n) to handle k > n
Step 2: Reverse entire array
Step 3: Reverse first k elements
Step 4: Reverse remaining n-k elements

Why this works:
Original:     [1, 2, 3, 4, 5, 6, 7]
After step 2: [7, 6, 5, 4, 3, 2, 1]
After step 3: [5, 6, 7, 4, 3, 2, 1]
After step 4: [5, 6, 7, 1, 2, 3, 4]  ✓

TIME COMPLEXITY: O(n) - Three passes through the array
SPACE COMPLEXITY: O(1) - No extra space needed (reverse is in-place)

ALTERNATIVE APPROACHES:
1. Extra Array Method: O(n) time, O(n) space
2. Cyclic Replacement: O(n) time, O(1) space (complex implementation)
3. Reversal (Current): O(n) time, O(1) space ⭐ BEST

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end()); // T.c = O(n)

    return nums;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;

    vector<int> v1 = rotate(v, k);

    for (auto el : v1)
    {
        cout << el << " " << endl;
    }

    return 0;
}