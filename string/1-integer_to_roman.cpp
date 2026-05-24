/*
================================================================================
LeetCode #12 - Integer to Roman (and LeetCode #13 - Roman to Integer)
================================================================================

PROBLEM STATEMENT (paraphrased):
- #12: Given an integer in the range 1..3999, convert it to a Roman numeral.
- #13: Given a valid Roman numeral string, convert it to an integer.

DIFFICULTY:
- #12: Medium
- #13: Easy

COMMONLY ASKED BY (varies by year/team):
- Amazon, Microsoft, Google, Meta, Bloomberg, Apple

ENTRY-LEVEL IMPORTANCE:
- High (string parsing/encoding and edge-case handling)

OPTIMAL APPROACH:
- Integer -> Roman: Greedy / place-value decomposition (thousands/hundreds/tens/ones).
    Time: O(1) (bounded by fixed digit groups), Space: O(1).
- Roman -> Integer: Scan left-to-right; if a symbol is smaller than the next symbol,
    subtract it, otherwise add it.
    Time: O(n), Space: O(1).

================================================================================
*/

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
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (i + 1 < (int)str.length() && mp[str[i]] < mp[str[i + 1]])
            ans -= mp[str[i]];
        else
            ans += mp[str[i]];
    }

    return ans;
}

int main()
{
    // Single test case (round-trip)
    int num = 1994;
    string roman = int_to_roman(num);
    int back = roman_to_int(roman);
    cout << "num=" << num << " roman=" << roman << " back=" << back << endl;

    return 0;
}