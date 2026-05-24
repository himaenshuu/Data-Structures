#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

// Find nth root using binary search

class Solution
{
public:
    double multiply(double x, int k)
    {
        double ans = 1.0;

        for (int i = 0; i < k; i++)
        {
            ans *= x;
        }

        return ans;
    }

    double nthRoot(int n, double m)
    {
        double low = 0;
        double high = m;

        double eps = 1e-6;

        while (high - low > eps)
        {
            double mid = low + (high - low) / 2.0;

            if (multiply(mid, n) < m)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        return low;
    }
};
//tc=

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    cout << sol.nthRoot(100,16) << endl;

    return 0;
}