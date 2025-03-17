// Reach to the target

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<vector<int>> threesum(vector<int> &nums, int size)
{
    vector<vector<int>> res;
    set<vector<int>> s; // set is similar to map.It has only one key. Or we can say it is group of elements.  
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0) // T.C = O(n^3)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                }
            }
        }
    }
    for (auto it : s)
    {
        res.push_back(it);
    }
    return res;
}
// T.C = O(n^3)

vector<vector<int>> threesum1(vector<int> &nums, int size)
{
    set<vector<int>> s;
    sort(nums.begin(), nums.end()); // T.C = O(n log n)

    for (int i = 0; i < size; i++) // T.C = O(n)
    {
        set<int> hs;                       // hashset
        for (int j = i + 1; j < size; j++) // T.C = O(n)
        {
            int third = -nums[i] - nums[j];

            if (hs.find(third) != hs.end()) // if it will not exists in hashset then it will return an end iterator
            {
                s.insert({nums[i], nums[j], third}); // T.C = O(log n)
            }
            hs.insert(nums[j]);
        }
    }
    vector<vector<int>> res(s.begin(), s.end());
    return res;
}
// final T.C = O(n^2 logn)

vector<vector<int>> threesum2(vector<int> &nums, int size)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < size; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1, k = size - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                res.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j + 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> v = threesum2(nums, n);

    if (!v.empty())
    {
        for (const auto &row : v)
        {
            for (const auto &el : row)
            {
                cout << el << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "NA";

    return 0;
}