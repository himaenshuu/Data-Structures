// // Find the minimum number of coins

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> v = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int val;
    int count = 0;
    cin >> val;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (val >= v[i])
        {
            val = val - v[i];
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

// t.c = O(n)