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
Given the root of a binary tree, invert the tree and return its root.

Inverting a binary tree means swapping the left and right child of every node
in the tree.

Difficulty:
Easy

Companies commonly asked:
Amazon, Microsoft, Google, Apple, Meta, Adobe, Oracle, Bloomberg, Uber, Walmart

Entry level importance:
High. This problem is frequently used to test tree recursion, node swapping,
and basic binary tree manipulation.

Optimal approach used:
Recursive DFS. Swap the left and right children of the current node, then apply
the same operation to both subtrees.

Time Complexity:
O(n), where n is the number of nodes in the tree.
Space Complexity:
O(h) recursion stack space, where h is the height of the tree.
*/

class Solution
{
public:
    void iT(TreeNode *root)
    {
        // idea kya h- swap left and right pointer of a node
        // and call the left and right recursively

        if (!root)
            return;

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        iT(root->left);
        iT(root->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        iT(root);
        return root;
    }
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    sol.invertTree(root);

    cout << "Test case 1 inverted preorder: ";
    print1darray(preorderTraversal(root));

    return 0;
}