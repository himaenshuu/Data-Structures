/*
============================================================
  FIND SMALLEST BALANCED INDEX
============================================================
  Problem Statement:
    Given an integer array nums, an index i is balanced if:
      Sum of all elements strictly to the left of i
      == Product of all elements strictly to the right of i
    - No elements to left  → left sum     = 0
    - No elements to right → right product = 1
    Return the smallest balanced index. If none, return -1.

  Constraints:
    1 <= nums.length <= 10^5
    1 <= nums[i]    <= 10^9

  Difficulty: Medium

  Companies: Amazon, Google, Microsoft, Adobe, Bloomberg
             (LeetCode Contest problem — Pivot-Index variant)

  Optimal Approach: O(n) time | O(n) space
  -------------------------------------------------------
  Step 1: Build suffix product array prod[] right-to-left
          prod[i] = product of nums[i..n-1], prod[n] = 1
          Clamp to LLONG_MAX on overflow (sentinel — can
          never equal leftSum which is at most 10^14).

  Step 2: Scan left-to-right with a running leftSum.
          For each i:
            if leftSum == prod[i+1]  →  return i
            leftSum += nums[i]

  Why O(n) space is irreducible:
    Right product needs a full right-to-left pass first,
    so the array must be stored before the left scan.
============================================================
*/
#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
  int smallestBalancedIndex(vector<int> &nums)
  {
    int n = nums.size();
    vector<long long> prod(n + 1, 1); // n+1 because we need prod[n] value as 1 too

    // long long sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      // If overflow, mark as LLONG_MAX (can never equal any valid left sum)
      if (prod[i + 1] == LLONG_MAX || prod[i + 1] > LLONG_MAX / nums[i])
        prod[i] = LLONG_MAX;
      else
        prod[i] = prod[i + 1] * nums[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
      if (sum == prod[i + 1])
        return i;
      sum = sum + nums[i];
    }

    return -1;
  }
  // tc=O(N)
  // sc=O(1)

  int smallestBalancedIndex1(vector<int> &nums)
  {
    unsigned long long left = std::accumulate(nums.begin(), nums.end(), 0ULL), right = 1;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
      left -= nums[i];
      if (left == right)
        return i;
      right *= nums[i];
      if (right > left)
        break;
    }
    return -1;
  }
};
// sc=O(1)
// tc=O(N)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  vector<int> nums1 = {2, 1, 2};
  cout << "Test 1: " << sol.smallestBalancedIndex1(nums1) << endl; // Expected: 1

  vector<int> nums2 = {2, 8, 2, 2, 5};
  cout << "Test 2: " << sol.smallestBalancedIndex1(nums2) << endl; // Expected: 2

  vector<int> nums3 = {1, 10, 2, 9, 2, 4, 4, 2, 8, 1, 8, 7, 1, 5, 7, 8, 3, 4, 9, 5, 10, 8, 10, 2, 7, 3, 1, 3, 4, 3, 9, 9, 4, 7, 8, 1, 1, 1, 9, 1, 10, 1, 1, 1, 2, 1};
  cout << "Test 3: " << sol.smallestBalancedIndex1(nums3) << endl;

  return 0;
}