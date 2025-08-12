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