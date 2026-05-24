#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

/*
Robust code
aproach kya h ?
find the kthFloorroot of left l and the right r
and then substract them

for nth root- use binary search method
*/

class Solution
{
public:
    bool powerLE(int x, int k, int limit)
    { // find the kth exponent and  return false if it exceeds the limit
        long long ans = 1;
        for (int i = 0; i < k; i++)
        {
            ans = ans * x;
            if (ans > limit)
                return false; // false means it exceeded the limit value
        }
        return true;
    }

    int kthRootFloor(int n, int k)
    {
        if (n < 0)
            return -1;
        if (n == 0)
            return 0;

        int l = 1;
        int r = n;
        int ans = 0;

        while (l <= r)
        {
            int mid = r + (l - r) / 2;
            if (powerLE(
                    mid, k,
                    n))
            { // If it return true, means root lies in right
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }

    int countKthRoots(int l, int r, int k)
    {
        if (k == 1)
            return r - l + 1;
        return kthRootFloor(r, k) - kthRootFloor(l - 1, k);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    ll l;
    ll r;
    int k;

    if (cin >> l >> r >> k)
    {
        cout << sol.countKthRoots(l, r, k) << endl;
    }

    return 0;
}
