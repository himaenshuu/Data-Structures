#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    string str1 = " Hello";
    string str2 = " World";
    cout << str1 + str2 << endl;

    cin >> str1; // this will only take one word as a input
    cout << str1 << endl;

    cin.ignore(); // this will clear '\n' left in the input buffer as each time we put something in cin it leaves a '\n' in the buffer

    // now for taking full sentence as a input-we use getline()
    string str3;
    getline(cin, str3);
    cout << str3 << endl; // this will print the full sentence
    return 0;
}