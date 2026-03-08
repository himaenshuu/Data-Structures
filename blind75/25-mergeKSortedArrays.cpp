/*
 * ============================================================
 * PROBLEM: Merge K Sorted Arrays
 * ============================================================
 * Given K sorted arrays of (possibly varying) sizes, merge them
 * into a single sorted array and return it.
 *
 * Example:
 *   Input : k = 3, arr = [[1, 3, 5],
 *                          [2, 4, 6],
 *                          [0, 7, 8]]
 *   Output: [0, 1, 2, 3, 4, 5, 6, 7, 8]
 *
 * Constraints:
 *   - 1 <= k <= 10^5
 *   - 1 <= arr[i].size() <= 10^5
 *   - Total elements N <= 10^6
 *   - Elements can be negative or positive integers
 *
 * DIFFICULTY: Medium
 *
 * TOP COMPANIES ASKED:
 *   Google, Amazon, Microsoft, Adobe, Samsung, Flipkart
 *
 * ============================================================
 * OPTIMAL APPROACH: Min-Heap (Priority Queue)
 * ============================================================
 * Intuition:
 *   At any point, the next smallest element in the merged output
 *   must be the smallest among the current front elements of all
 *   K arrays. A min-heap lets us efficiently extract that minimum
 *   and immediately insert the next candidate from the same array.
 *
 * Algorithm:
 *   1. Push the first element of every array into a min-heap
 *      as a tuple (value, arrayIndex, elementIndex).
 *   2. While the heap is non-empty:
 *        a. Pop the minimum (val, row, col).
 *        b. Append val to result.
 *        c. If col+1 < arr[row].size(), push arr[row][col+1].
 *   3. Return result.
 *
 * Time  : O(N log K)  — N total elements, each heap op is O(log K)
 * Space : O(K)        — heap holds at most K elements at a time
 * ============================================================
 */

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
    {
        vector<int> result;

        // Min-heap: (value, rowIndex, colIndex)
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>>
            pq;

        // Seed heap with the first element of each array
        for (int i = 0; i < k; i++)
        {
            if (!arr[i].empty())
                pq.push({arr[i][0], i, 0});
        }

        while (!pq.empty())
        {
            auto [val, row, col] = pq.top();
            pq.pop();
            result.push_back(val);

            // Push the next element from the same array if it exists
            if (col + 1 < (int)arr[row].size())
            {
                pq.push({arr[row][col + 1], row, col + 1});
            }
        }

        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test Case 1: 3 sorted arrays of equal size
    // Expected output: 0 1 2 3 4 5 6 7 8
    {
        vector<vector<int>> arr = {
            {1, 3, 5},
            {2, 4, 6},
            {0, 7, 8}};
        vector<int> res = sol.mergeKSortedArrays(arr, arr.size());
        cout << "Test 1: ";
        for (int x : res)
            cout << x << " ";
        cout << endl;
    }

    // Test Case 2: arrays of varying sizes with negative numbers
    // Expected output: -5 -2 0 1 3 4 6 9 10
    {
        vector<vector<int>> arr = {
            {-5, 1, 9},
            {-2, 3, 6, 10},
            {0, 4}};
        vector<int> res = sol.mergeKSortedArrays(arr, arr.size());
        cout << "Test 2: ";
        for (int x : res)
            cout << x << " ";
        cout << endl;
    }
    
    return 0;
}