// LeetCode: https://leetcode.com/problems/subtree-of-another-tree/
// Problem Statement: Check whether subRoot is a subtree of root with the same structure and node values.
// Optimal Approach: Serialize both trees using preorder with null markers, then check whether subRoot serialization exists inside root serialization.
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode *subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;
    cout << "Expected: true" << endl;
    cout << "Actual: " << boolalpha << sol.isSubtree(root, subRoot) << endl;

    return 0;
}
