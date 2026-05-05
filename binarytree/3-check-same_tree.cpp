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

/*
Problem Statement:
Given the roots of two binary trees p and q, check whether the two trees are
the same.

Two binary trees are considered the same if they have the same structure and the
nodes have the same values in corresponding positions.

Difficulty:
Easy

Companies commonly asked:
Amazon, Microsoft, Google, Apple, Meta, Adobe, Oracle, Bloomberg, Uber, Walmart

Entry level importance:
High. This is a standard binary tree comparison problem and is often used to
evaluate recursion and structural reasoning.

Optimal approach used:
Recursive DFS. Compare both trees node by node, returning false if one node is
missing or values differ, and true only when both subtrees match completely.

Time Complexity:
O(n), where n is the number of nodes in the smaller or matched tree traversal.
Space Complexity:
O(h) recursion stack space, where h is the height of the tree.
*/

class Solution
{
public:
    bool ist(TreeNode *a, TreeNode *b)
    {
        // check for both null case
        if (!a && !b)
            return true;
        // check for one of them null case
        if (!a || !b)
            return false;
        // if their values are equal move further else return false
        if (a->val == b->val)
            return (ist(a->left, b->left) && ist(a->right, b->right));
        return false;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) { return ist(p, q); }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    cout << boolalpha;

    TreeNode *p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);
    p1->left->left = new TreeNode(4);
    p1->left->right = new TreeNode(5);

    TreeNode *q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);
    q1->left->left = new TreeNode(4);
    q1->left->right = new TreeNode(5);

    cout << "Test case 1 is same tree: " << sol.isSameTree(p1, q1) << endl;

    return 0;
}