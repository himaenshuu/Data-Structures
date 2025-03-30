#include <bits/stdc++.h>
typedef long long ll;
// typedef vector<int> vi;
using namespace std;

vector<int> sort(vector<int> v)
{
    sort(v.begin(), v.end());
    return v;
}

int main()
{
    // write your code here
    int n, m;
    cin >> n >> m;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v1.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        v2.push_back(temp);
    }

    if (v1 == sort(v1) && v2 == sort(v2))
    {
        vector<int> v(v1.size() + v2.size());
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());

        for (auto el : v)
        {
            cout << el << " ";
        }
    }

    else
    {
        if (v1.size() > v2.size())
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << v1[i] << " ";
            }
        }
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << v2[i] << " ";
            }
        }
    }

    return 0;
}