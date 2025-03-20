#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void remove_duplicates(vector<int> &vect)
{
    int n = vect.size();

    int i = 0, low = 0, mid = 1;

    while (mid < n)
    {
        if (vect[mid] > vect[i])
        {
            vect[low + 1] = vect[mid];
            low++;
            mid++;
            i++;
        }

        else
            mid++;
    }
    for (int i = 0; i <= low; i++)
    {
        cout << vect[i] << " ";
    }
}
// Inplace algorithm
// T.c = O(n)
// S.c = O(1)

int main()
{
    vector<int> v = {0,0,1,1, 2, 2, 3, 4, 4, 5, 6};
    remove_duplicates(v);

    return 0;
}