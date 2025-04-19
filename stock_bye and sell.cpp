#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int findmaxprofit(vector<int> &prices)
{
    int size = prices.size();

    int sum = 0;
    int max_profit = 0;

    for (int i = 1; i < size; i++)
    {
        sum += prices[i] - prices[i - 1];
        if (sum < 0)
        {
            sum = 0;
        }
        max_profit = (sum > max_profit) ? sum : max_profit;
    }

    return max_profit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vect(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vect[i];
    }
    cout << findmaxprofit(vect);

    return 0;
}