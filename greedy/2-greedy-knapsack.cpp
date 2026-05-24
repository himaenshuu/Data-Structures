/*
================================================================================
Fractional Knapsack Problem (Greedy Approach)
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Google
- Adobe
- Samsung
- Flipkart
- Paytm
 
PROBLEM STATEMENT:
The weight of N items and their corresponding values are given. We have to put
these items in a knapsack of weight W such that the total value obtained is
maximized. We can take fractions of items.

CONSTRAINTS:
- 1 <= N <= 10^5
- 1 <= W <= 10^9
- 1 <= value[i], weight[i] <= 10^4

EXAMPLE:
Input: N = 3, W = 50
value[] = {60, 100, 120}
weight[] = {10, 20, 30}
Output: 240.00
Explanation: Take full items 2 and 3, and 2/3 of item 1
Total = 100 + 120 + (2/3)*60 = 240

GREEDY APPROACH:
1. Calculate value/weight ratio for all items
2. Sort items by ratio in descending order
3. Pick items with highest ratio first
4. Take fractions if needed for remaining capacity

WHY GREEDY WORKS:
For fractional knapsack, taking items with highest value-to-weight ratio
always gives optimal solution.

APPROACH 1 (maxValue): Bubble sort - O(n²)
APPROACH 2 (maxValue2): Built-in sort - O(n log n) ⭐ OPTIMAL

NOTE: For 0/1 Knapsack (no fractions), use Dynamic Programming!

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define fd(a, b) float(a / b)
 
int maxValue(vector<int> &value, vector<int> &weight, int w)
{
    int n = value.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (fd(value[j], weight[j]) < fd(value[j + 1], weight[j + 1]))
            {
                swap(value[j], value[j + 1]);
                swap(weight[j], weight[j + 1]);
            }
        }
    }

    int val = 0;

    for (int i = 0; i < n; i++)
    {
        if (w >= weight[i])
        {
            val += value[i];
            w = w - weight[i];
        }
        else
        {
            val += (w * fd(value[i], weight[i]));
        }
    }
    return val;
}
// t.c = O(n^2)

int maxValue2(vector<int> &value, vector<int> &weight, int w)
{
    int n = value.size();

    // Pair value and weight, then sort by value/weight ratio in descending order
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++)
    {
        items[i] = {value[i], weight[i]};
    }
    auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        return (double)a.first / a.second > (double)b.first / b.second;
    };
    sort(items.begin(), items.end(), comp);
    for (int i = 0; i < n; i++)
    {
        value[i] = items[i].first;
        weight[i] = items[i].second;
    }

    int val = 0;
    for (int i = 0; i < n; i++)
    {
        if (w >= weight[i])
        {
            val += value[i];
            w = w - weight[i];
        }
        else
        {
            val += (w * fd(value[i], weight[i]));
        }
    }
    return val;
}
// t.c = O(n*logn)

int main()
{
    int n, w;
    cin >> n >> w; // number of items and weight of knapsack
    vector<int> value(n), weight(n);

    for (int i = 0; i < n; i++)
    {
        cin >> value[i]; // value of each item
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i]; // weight of each item
    }

    cout << maxValue(value, weight, w);

    return 0;
}
