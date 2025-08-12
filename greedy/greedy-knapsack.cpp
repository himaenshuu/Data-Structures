/*
Problem Statement : The weight of N items and their corresponding values are given.We have to put these items in a knapsack of weight W such that the total value obtained is maximized.
We are using greedy approach to solve this problem.
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
