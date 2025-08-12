// Rearrange elements by sign such that it occurs in an alternate order

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> rearrange(const vector<int> &vect)
{
    int size = vect.size();
    vector<int> v(size, 0);
    int k = 0;

    for (int i = 0; i < size; i++)
    {
        if (vect[i] > 0)
        {
            v[k] = vect[i];
            k = k + 2;
        }
    }
    k = 1;
    for (int i = 0; i < size; i++)
    {
        if (vect[i] < 0)
        {
            v[k] = vect[i];
            k = k + 2;
        }
    }

    return v;
}

int main()
{
    vector<int> v = rearrange({1, -2, -3, 4});

    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}