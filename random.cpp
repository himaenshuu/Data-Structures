#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> twosum(const vector<int> &vect, int target)
{
    int n = vect.size();
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int comp = target - vect[i];

        if (mp.count(comp))
        {
            return {mp[comp],i};
        }

        mp[vect[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> v = twosum({2, 3, 5, 8, 9}, 17);

    for (auto &el : v)
    {
        cout << el << " ";
    }
    return 0;
}