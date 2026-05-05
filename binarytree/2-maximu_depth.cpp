#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

/*
Problem Statement:
Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path from the root
node down to the farthest leaf node.

Difficulty:
Easy

Companies commonly asked:
Amazon, Microsoft, Google, Apple, Meta, Adobe, Oracle, Bloomberg, Uber, Walmart

Entry level importance:
High. This is one of the most common recursive tree problems and is useful for
building confidence with DFS and height-based tree logic.

Optimal approach used:
Recursive DFS. Compute the depth of the left and right subtrees and return the
larger one plus one for the current node.

Time Complexity:
O(n), where n is the number of nodes in the tree.
Space Complexity:
O(h) recursion stack space, where h is the height of the tree.
*/

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
    int fd(TreeNode *root, int d)
    {
        if (!root)
            return 0;
        // go left
        int left = 1 + fd(root->left, d);
        // go right
        int right = 1 + fd(root->right, d);

        return max(left, right);
    }

    int maxDepth(TreeNode *root)
    {
        int depth = fd(root, 0);
        return depth;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Test case 1 max depth: " << sol.maxDepth(root) << endl;

    return 0;
}