#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) 
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        sort(v.begin(), v.end());
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] == v[i + 1])
            {
                // cout << "YES" << "\n";
                // return 0;
                count++;
            }
        }

        if (count)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}