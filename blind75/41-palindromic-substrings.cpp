#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            // odd
            int l = i, r = i;
            while (l >= 0 && r <= n - 1 && s[l] == s[r])
            {
                l--;
                r++;
                count++;
            }
            // even
            l = i, r = i + 1;
            while (l >= 0 && r <= n - 1 && s[l] == s[r])
            {
                l--;
                r++;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}