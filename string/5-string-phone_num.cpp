/*
================================================================================
LeetCode #17 - Letter Combinations of a Phone Number
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED:
- Amazon
- Google
- Meta (Facebook)
- Microsoft
- Apple
- Uber
- Bloomberg
- Oracle
- LinkedIn

PROBLEM STATEMENT:
Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons):
2 → "abc"
3 → "def"
4 → "ghi"
5 → "jkl"
6 → "mno"
7 → "pqrs"
8 → "tuv"
9 → "wxyz"

CONSTRAINTS:
- 0 <= digits.length <= 4
- digits[i] is a digit in the range ['2', '9']

EXAMPLE 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Explanation:
2 maps to "abc"
3 maps to "def"
All combinations: a+d, a+e, a+f, b+d, b+e, b+f, c+d, c+e, c+f

EXAMPLE 2:
Input: digits = ""
Output: []

EXAMPLE 3:
Input: digits = "2"
Output: ["a","b","c"]

APPROACH 1: Nested Loops (Current - Limited)
- Only works for fixed length inputs (up to 4 digits)
- Hardcoded nested loops
- Time Complexity: O(4^n) where n is length
- Space Complexity: O(4^n) for output
- ❌ Not scalable, messy code

APPROACH 2: Backtracking (Recursive) ⭐ OPTIMAL
- Build combinations character by character
- Explore all paths using recursion
- Backtrack when combination is complete
- Time Complexity: O(4^n × n)
- Space Complexity: O(n) for recursion stack + O(4^n) for output
- ✅ Clean, scalable, efficient

BACKTRACKING EXPLANATION:
1. Start with empty string
2. For current digit, try each letter mapping
3. Recursively build rest of combination
4. When length matches input, add to result
5. Backtrack to explore other possibilities

PATTERN: This is a classic BACKTRACKING problem
- Generate all possible combinations
- Decision tree exploration
- Build incrementally and backtrack

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// APPROACH 1: Nested Loops (Your original - Limited to 4 digits)
// ❌ Not recommended - doesn't handle edge cases properly
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
// T.C = O(4^n) S.C = O(4^n) - Only works for inputs <= 4 digits

// APPROACH 2: Backtracking (Recursive) ⭐ OPTIMAL & SCALABLE
void backtrack(string &digits, int index, string current,
               unordered_map<char, string> &mp, vector<string> &result)
{
    // Base case: reached end of digits
    if (index == digits.length())
    {
        result.push_back(current);
        return;
    }

    // Get letters for current digit
    string letters = mp[digits[index]];

    // Try each letter
    for (char c : letters)
    {
        backtrack(digits, index + 1, current + c, mp, result);
    }
}

vector<string> letterCombinationsOptimal(string digits)
{
    vector<string> result;

    // Edge case: empty input
    if (digits.empty())
        return result;

    // Phone number mapping
    unordered_map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    backtrack(digits, 0, "", mp, result);
    return result;
}
// T.C = O(4^n × n) S.C = O(n) recursion stack

int main()
{
    // Test Case 1
    string digits1 = "23";
    vector<string> result1 = letterCombinationsOptimal(digits1);
    cout << "Input: \"" << digits1 << "\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++)
    {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1)
            cout << ",";
    }
    cout << "]" << endl
         << endl;

    // Test Case 2
    string digits2 = "";
    vector<string> result2 = letterCombinationsOptimal(digits2);
    cout << "Input: \"" << digits2 << "\"" << endl;
    cout << "Output: []" << endl
         << endl;

    // Test Case 3
    string digits3 = "2";
    vector<string> result3 = letterCombinationsOptimal(digits3);
    cout << "Input: \"" << digits3 << "\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++)
    {
        cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;

    return 0;
}