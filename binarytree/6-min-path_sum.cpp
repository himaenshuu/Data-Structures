// LeetCode: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Problem Statement: Find the maximum path sum in a binary tree, where a path can start and end at any node.
// Optimal Approach: Use postorder DFS, return the best one-side gain to parent, and update a global answer with left + node + right.
// Time Complexity: O(n)
// Space Complexity: O(h)

#include <bits/stdc++.h>
#include "../utilities.h"
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

    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Expected: 42" << endl;
    cout << "Actual: " << sol.maxPathSum(root) << endl;

    return 0;
}
