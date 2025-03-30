/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t, n, a;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);
        }
        if (n % 2 != 0 && n % 3 == 0)
        {
            cout << v[n / 2];
        }
        else
        {
            if (n % 2 == 0 && n % 3 == 0)
            {
                cout << *v.begin() << " " << *v.end();
            }
            else
            {
                cout << *(v.begin()) + *(v.end());
            }
        }
    }
}
*/
// Partial Sum //

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int main()
// {
//     vector<ll> v1;
//     v1 = {1, 2, 3, 4, 5};
//     vector<ll> v2(v1.size());

//     partial_sum(v1.begin(), v1.end(), v2.begin());
//     for (auto el : v2)
//     {
//         cout << el << " ";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     // Write your code here
//     vector<int> v;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int temp;
//         cin >> temp;
//         v.push_back(temp);
//     }

//     sort(v.begin(), v.end());
//     for (int el : v)
//     {
//         cout << el << " ";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// typedef vector<int> vi;
// typedef vector<float> vf;
// int main()
// {
//     vi v = {1, 2, 3, 4, 5};
//     // for (auto temp : v)
//     // {
//     //     cout << temp << " ";
//     // }

//     cout << *upper_bound(v.begin(), v.end(), 3);
//     return 0;
// }