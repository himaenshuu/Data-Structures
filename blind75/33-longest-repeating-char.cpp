#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;
        int mf = 0; // it will store the maximum frequency
        // traverse the string array with right=0 -> n
        // store the frequency of each char,
        // check if it forms the valid window , if window size exceeds the value=k

        vector<int> freq(26, 0); // assuming the 0 based indexing
        // A =0, B=1

        for (int r = 0; r < n; r++)
        {
            freq[s[r] - 'A']++; //
            mf = max(mf, freq[s[r] - 'A']);

            while (r - l + 1 - mf > k) // check if window is valid
            {
                freq[s[l] - 'A']--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}