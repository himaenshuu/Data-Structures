#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    void preorder(TreeNode *root, string &ans)
    {
        if (!root)
        {
            ans += "#,"; // stoppage mark to identify this edge have null
            return;
        }

        ans += "," + to_string(root->val) + ","; // we need to apply comma on both side to keep each digit isolated and unique
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        string r1 = "";
        preorder(root, r1);

        string r2 = "";
        preorder(subRoot, r2);

        // perform a match
        if (r1.find(r2) != string::npos)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}