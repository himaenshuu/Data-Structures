#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    string s = "123456"; // input string

    // now if we want to extract each digit as an integer from this string

    for (int i = 0; i < s.size(); i++)
    {
        int a = s[i] - '0';
        cout << a << " ";
    }

    return 0;
}