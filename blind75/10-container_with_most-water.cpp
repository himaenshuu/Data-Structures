#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

// two pointer approach
// t.c = O(n)

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        int sum = 0;

        while (i < j)
        {
            int area = min(height[i], height[j]) * (j - i);
            sum = (area > sum) ? area : sum;

            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vect = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution sol;

    cout << sol.maxArea(vect)<< endl;

    return 0;
}