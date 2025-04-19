#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<string> letterCombinations(string digits)
{
    int flag = digits.length();
    unordered_map<char, string> mp;
    vector<string> vect;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    for (int i = 0; i < mp[digits[0]].length(); i++)
    {
        string str;
        str += mp[digits[0]][i];
        for (int j = 0; j < mp[digits[1]].length(); j++)
        {
            str += mp[digits[1]][j];
            if (flag == 2)
            {
                vect.push_back(str);
                str.pop_back();
            }
            for (int k = 0; k < mp[digits[2]].length(); k++)
            {
                str += mp[digits[2]][k];
                if (flag == 3)
                {
                    vect.push_back(str);
                    str.pop_back();
                }
                for (int l = 0; l < mp[digits[3]].length(); l++)
                {
                    str += mp[digits[3]][l];
                    if (flag == 4)
                    {
                        vect.push_back(str);
                        str.pop_back();
                    }
                }
            }
        }

        if (str.length() >= digits.length())
            vect.push_back(str);
    }

    return vect;
};

int main()
{
    string digits = "234";
    vector<string> result = letterCombinations(digits);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}