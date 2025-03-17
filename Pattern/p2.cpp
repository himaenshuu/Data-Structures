#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void printstar(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int start;
        if (i % 2 == 0)
            start = 0;
        else
            start = 1;
        for (int j = 0; j < i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

int main()
{
    printstar(5);

    return 0;
}