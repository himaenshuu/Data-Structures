#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    bool SubsetSum(int start, int value, vector<int> &vect)
    {
        int n = vect.size();
        if (start > n)
            return false;

        // outbond cases
        for (int i = start; i < n; i < i++)
        {
            if (vect[start] + vect[i] == value)
                return true;
        }

        return SubsetSum(start + 1, value, vect);
    }

    // I have to return whether it is present or not
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vect[i];
    }

    int k;
    cin >> k;

    Solution obj;

    if (obj.SubsetSum(0, k, vect))
        cout << "yes" << endl;

    else
        cout << "NO" << endl;
    return 0;
}
