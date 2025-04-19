#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

string int_to_roman(int num)
{
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hunds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string thous[] = {"", "M", "MM", "MMM"};

    return thous[num / 1000] + hunds[(num % 1000 / 100)] + tens[(num % 100) / 10] + ones[(num % 10)];
}

int roman_to_int(string str)
{
    map<char, int> mp;

    mp['I'] = 1, mp['V'] = 5, mp['X'] = 10, mp['L'] = 50, mp['C'] = 100, mp['D'] = 500, mp['M'] = 1000;

    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (mp[str[i]] < mp[str[i + 1]])
            ans -= mp[str[i]];

        else
            ans += mp[str[i]];
    }

    return ans;
}

int main()
{
    cout << int_to_roman(234)
         << endl;
    cout << roman_to_int("LXIV");

    return 0;
}