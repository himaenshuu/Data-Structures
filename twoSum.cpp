#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        vector<int> nums;
        for (int i = 0; i < size; i++)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        int target;
        cin >> target;

        unordered_map<int, int> unmap;
        for (int i = 0; i < size; i++)
        {
            unmap[nums[i]] = i;
        }

        for (int i = 0; i < size; i++)
        {
            int complement = target - nums[i];
            if (unmap.count(complement))
            {
                cout << i << " " << unmap[complement] << endl;
                break;
            }
        }
    }
}