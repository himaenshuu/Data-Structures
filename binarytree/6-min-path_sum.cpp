#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int dfs(TreeNode *root, int &maxi)
    {
        // go to left and right and take only postive value
        // keep updating a global maxi
        if (!root)
            return 0;
        int leftsum = max(0, dfs(root->left, maxi));
        int rightsum = max(0, dfs(root->right, maxi));
        maxi = max(maxi, leftsum + rightsum + root->val);
        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}