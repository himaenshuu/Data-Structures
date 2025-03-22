// move zeroes to right end

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> moveZeros(int n, vector<int> a)
{
    // Write your code here.
    vector<int> b;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            b.push_back(a[i]);
        else
            cnt++;
    }

    while (cnt--)
        b.push_back(0);

    return b;
}

// more Optimal approach

vector<int> moveZeros1(int n, vector<int> a)
{
    // Write your code here.
    int j = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return a;

    for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

int main()
{
    vector<int> v = {1, 0, 3, 4, 5, 0, 5, 0, 7};
    vector<int> v1 = moveZeros1(9, v);

    for (auto &el : v1)
    {
        cout << el << " ";
    }

    return 0;
}