#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// vector<vector<int>> mergetwoarrays(vector<int> &nums1, vector<int> &nums2)
// {
//     int n1 = nums1.size(), n2 = nums2.size();
//     map<int, int> mp1;

//     for (int i = 0; i < n1; i++)
//     {
//         mp1[nums1[i][0]] = nums1[i][1];
//     }

//     for (auto &el : mp1)
//     {
//         cout << el.first << " " << el.second << endl;
//     }
// }

int main()
{
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    map<int, int> mp1;

    for (int i = 0; i < 3; i++)
    {
        mp1[nums1[i][0]] = nums1[i][1];
    }

    for (auto &el : mp1)
    {
        cout << el.first << " " << el.second << endl;
    }
    cout << "" << endl;

    return 0;
}