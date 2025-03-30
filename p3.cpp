#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    // write your code here
    vector<int> v;
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == x)
            a += 1;

        v.push_back(a);
    }

    for (auto el : v)
    {
        cout << el << " ";
    }

    return 0;
}