#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
    {
        // Your code goes here
        for (int i = 0; i < k; i++)
        {
            int min = arr[0][i];
            for (int j = 0; j < k; j++)
            {
                if (arr[j][i] < min)
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}