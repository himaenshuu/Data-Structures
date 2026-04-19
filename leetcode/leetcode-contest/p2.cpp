#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &a, int k)
    {
        int n = static_cast<int>(a.size());
        if (n == 0)
        {
            return -1;
        }

        vector<int> mr(n);
        mr[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            mr[i] = min(a[i], mr[i + 1]);
        }

        int ml = numeric_limits<int>::min();
        for (int i = 0; i < n; i++)
        {
            ml = max(ml, a[i]);
            int d = ml - mr[i];
            if (d <= k)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
