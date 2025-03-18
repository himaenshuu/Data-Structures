#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

bool checkifsorted(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            count++;
            if (count > 1)
                return false; // More than one drop means not a rotated sorted array
        }
    }
    if (nums[n - 1] > nums[0]) // the last element must still be ≤ the first element if the array is a valid rotated sorted sequence
        count++;
    return count <= 1;
}
// t.c = O(n)
int main()
{
    vector<int> v = {3, 4, 5, 1, 2};
    if (checkifsorted(v))
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;

    // checkifsorted(v);

    return 0;
}