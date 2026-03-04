#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int mi = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > mi)
                return false;
            else
            {
                mi = max(mi, i + nums[i]);
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}