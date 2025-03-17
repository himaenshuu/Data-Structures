#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> remove_target(vector<int> &nums, int target)
{
    int n = nums.size();
    auto it = find(nums.begin(), nums.end(), target); // t.c = o(n)
    int index = -1;

    if (it != nums.end())
        index = distance(nums.begin(), it);

    if (index == -1)
        return nums;

    for (int i = index; i < n; i++)
    {
        if (nums[i] != nums[index])
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return nums;
}

// above code works for sorted vector  , early stage logic

vector<int> remove_target1(vector<int> &nums, int target)
{
    int n = nums.size();
    int index = 0;

    for (int i = 0; i < n; i++) // T.C = O(n)
    {
        if (nums[i] != target)
        {
            nums[index] = nums[i];
            index++;
        }
    }
    nums.resize(index);
    return nums;
}

// it works for all

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int t;
    cin >> t;

    vector<int> v1 = remove_target1(v, t);

    for (auto el : v1)
    {
        cout << el << " " << endl;
    }

    return 0;
}
