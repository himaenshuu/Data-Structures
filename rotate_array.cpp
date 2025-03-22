#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin() + k, nums.end()); // T.c = O(n)

    return nums;
}

vector<int> rotatenewtype(vector<int> &nums, int k)
{
    while ()
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;

    vector<int> v1 = rotate(v, k);

    for (auto el : v1)
    {
        cout << el << " " << endl;
    }

    return 0;
}