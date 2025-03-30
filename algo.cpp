// // Hash table for integer

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> v1, v2;
//     cout << "Train vector\n";
//     int x;
//     while (true)
//     {
//         cin >> x;
//         if (x == 0)
//         {
//             break;
//         }
//         v1.push_back(x);
//     }
//     cout << "test vector\n";
//     x = -1;
//     while (1)
//     {
//         cin >> x;
//         if (x == 0)
//         {
//             break;
//         }
//         v2.push_back(x);
//     }
//     int max = *max_element(v1.begin(), v1.end());
//     vector<int> v(max, 0);

//     for (int i = 0; i < v1.size(); i++)
//     {
//         v[v1[i]]++;
//     }
//     cout << "Hash-Table" << endl;
//     for (int i = 0; i < v2.size(); i++)
//     {
//         cout << v[v2[i]] << " ";
//     }
//     return 0;
// }

// Hash table for character
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {'a'};
    char c = 97;
    cout << c;
    cout << v[0];

    return 0;
}