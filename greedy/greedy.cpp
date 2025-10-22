/*
================================================================================
LeetCode #455 - Assign Cookies (Greedy)
================================================================================

DIFFICULTY: Easy ⭐

COMPANIES ASKED:
- Amazon
- Google
- Microsoft
- Adobe
- Facebook

PROBLEM STATEMENT:
You want to give cookies to children. Each child i has a greed factor g[i],
which is the minimum size of cookie that will make the child content. Each
cookie j has size s[j]. You can only give one cookie to each child.

Your goal is to maximize the number of content children.

CONSTRAINTS:
- 1 <= g.length <= 3 * 10^4
- 0 <= s.length <= 3 * 10^4
- 1 <= g[i], s[j] <= 2^31 - 1

EXAMPLE 1:
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: Only one child can be content

EXAMPLE 2:
Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: Both children can be content

GREEDY APPROACH:
1. Sort both greed factors and cookie sizes
2. Try to satisfy children with smallest greed first
3. Use smallest cookie that satisfies each child
4. This maximizes total satisfied children

TIME COMPLEXITY: O(n log n + m log m)
SPACE COMPLEXITY: O(1)

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void print(vector<int> v)
{
    for (auto &el : v)
    {
        cout << el << " ";
    }
}

int minChild(vector<int> value, vector<int> v2) // O(n logn)
{
    sort(value.begin(), value.end());
    sort(v2.begin(), v2.end());

    int j = 0;
    int count = 0;
    for (int i = 0; i < v2.size(), j < value.size(); i++)
    {
        if (v2[i] >= value[j])
        {
            j++;
            count++;
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> greedyFactors(n), cookieSizes(m);

    for (int i = 0; i < n; i++)
    {
        cin >> greedyFactors[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cookieSizes[i];
    }
    // print(greedyFactors);
    // print(cookieSizes);
    int k = minChild(greedyFactors, cookieSizes);
    cout << k;

    return 0;
}