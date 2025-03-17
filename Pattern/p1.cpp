#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void printstar(int n)
{
    for (int i = 1; i <= n; i++)
        cout << string(i, '*') << endl;
    for (int i = n - 1; i > 0; i--)
        cout << string(i, '*') << endl;
}

void printtriangle(int n) 
{
    for (int i = 0; i < n; i++)
        cout << string(n - i - 1, ' ') << string(2 * i + 1, '*') << endl;
}

void printtriangle2(int n) // revrese of the above
{
    for (int i = 0; i < n; i++)
        cout << string(i, ' ') << string(2 * (n - i) - 1, '*') << endl;
}

int main()
{
    printstar(5);
    cout << "break" << endl;
    printtriangle(5);
    // cout << "reverse of the above" << endl;
    printtriangle2(5);

    return 0;
}
