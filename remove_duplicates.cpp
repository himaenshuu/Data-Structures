#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void remove_duplicates(vector<int> &vect)
{
    int n = vect.size(), index = 1;
    for (int i = 1; i < n; i++)
    {
        if (vect[i] != vect[i - 1])
        {
            vect[index] = vect[i];
            index++;
        }
    }
    for (int i = 0; i <= index; i++)
    {
        cout << vect[i] << " ";
    }
}
// Inplace algorithm
// T.c = O(n)
// S.c = O(1)

int main()
{
    vector<int> v = {0, 0, 1, 1, 2, 2, 3, 4, 4, 5, 6};
    remove_duplicates(v);

    return 0;
}