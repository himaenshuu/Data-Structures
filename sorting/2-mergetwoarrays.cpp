#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> mergearrays(const vector<int> &v1, const vector<int> &v2)
{
    int n1 = v1.size();
    int n2 = v2.size();

    vector<int> v3(n1 + n2, 0);

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (v1[i] < v2[j])
        {
            v3[k++] = v1[i++];
        }

        else
        {
            v3[k++] = v2[j++];
        }
    }

    while (j < n2)
    {
        v3[k++] = v2[j++];
    }

    while (i < n2)
    {
        v3[k++] = v1[i++];
    }
    
    return v3;
}

int main()
{
    vector<int> v1, v2, v3;
    v1 = {1, 3, 4, 5};
    v2 = {3, 4, 5, 7, 8, 9};
    v3 = mergearrays(v1, v2);

    for (auto &el : v3)
    {
        cout << el << " ";
    }

    return 0;
}