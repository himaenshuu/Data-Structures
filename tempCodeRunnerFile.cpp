#include <bits/stdc++.h>

using namespace std;

int myfun(int x, int y)
{
    return x * y;
}

int main()
{
    // your code goes here
    int t, a, n;
    cin >> t;
    while (t--)
    {
        vector<int> v1;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a;
            v1.push_back(a);
        }

        vector<int> v2(n);
        partial_sum(v1.begin(), v1.end(), v2.begin());
        int prod = accumulate(v2.begin(), v2.end(), 1, myfun);

        cout << prod << " ";

        if ((prod % *max_element(v1.begin(), v1.end())) == 0 && (prod % *min_element(v1.begin(), v1.end())) == 0)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}