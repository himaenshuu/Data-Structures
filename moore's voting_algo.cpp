#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int findmajority(vector<int> &vect)
{
    int count = 0, el = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (count == 0)
        {
            count++;
            el = vect[i];
        }
        else
        {
            if (vect[i] != el)
            {
                count--;
            }
            else
                count++;
        }
    }

    return el;
}

int main()
{
    vector<int> v = {1, 2, 2, 3, 2, 4, 2};

    int num = findmajority(v);

    cout << num << endl;
    return 0;
}

