#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int k = 45, i = 4;
    double val = pow(i, 1.0 / k);
    if(val==round(val))
        cout << "True";

    else cout << "false";
    return 0;
}
