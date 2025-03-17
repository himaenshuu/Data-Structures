#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<vector<int>> rotate_image(vector<vector<int>> &nums)
{
    int n = nums.size();
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
               swap(nums[i][j] , nums[j][i]);
        }
    }

    for (int j = 0; j < n;j++){
        reverse(nums[j].begin(), nums[j].end());
    }

        return nums;
}

// total t.c = O(n^2)

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> v1 = rotate_image(v);

    for (const auto &row : v1)
    {
        for (auto el : row)
        {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}