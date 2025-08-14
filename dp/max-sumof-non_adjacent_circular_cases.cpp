#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// in this case i will divide the case in two
// one which contains first(index=0) and exclude the last (n-1)
// second which conatins second(index=1) and include the last (n-1)
// then we will seclect the max of the both

class Solution
{
public:
    int fun(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 1)
            return arr[0];

        if (n == 2)
            return max(arr[0], arr[1]);

        vector<int> dp1(n, -1);
        dp1[0] = arr[0];
        dp1[1] = max(arr[0], arr[1]);

        // dp[i] is storing the value of max sum possible upto i

        for (int i = 2; i < n - 1; i++)
        {
            dp1[i] = max(arr[i] + dp1[i - 2], dp1[i - 1]);
        }

        vector<int> dp2(n, -1);
        dp2[1] = arr[1];
        dp2[2] = max(arr[2], arr[1]);

        for (int i = 3; i < n; i++)
        {
            dp2[i] = max(arr[i] + dp2[i - 2], dp2[i - 1]);
        }

        return max(dp2[n - 1], dp1[n - 2]);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution obj;
    cout << obj.fun(v) << endl;
    return 0;
}

// space optimized solution-O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int robCircular(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(
            robLinear(nums, 0, n - 2),
            robLinear(nums, 1, n - 1));
    }

    int robLinear(vector<int> &nums, int start, int end)
    {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++)
        {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

