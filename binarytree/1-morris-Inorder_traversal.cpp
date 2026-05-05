/*
Problem Statement:
Given the root of a binary tree, return the inorder traversal of its nodes' values.
Inorder traversal visits nodes in the order: left subtree, root, right subtree.

Difficulty:
Easy

Companies commonly asked:
Amazon, Microsoft, Google, Apple, Meta, Adobe, Oracle, Bloomberg, Uber, Walmart

Entry level importance:
High. This is a core binary tree traversal problem and is frequently used to test recursion,
iteration, and pointer handling fundamentals.

Optimal approach used:
Morris inorder traversal. It temporarily threads the tree using right pointers of the
inorder predecessor so the traversal runs without recursion and without an auxiliary stack.

Time Complexity:
O(n), where n is the number of nodes in the tree.
Space Complexity:
O(1) extra space.
*/

#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"
// morris inorder traversal - no recursion, stack and extra data structure
class Solution
{
public:
    struct node
    {
        int val;
        node *left;
        node *right;

        node(int value)
        {
            val = value;
            left = NULL;
            right = NULL;
        }
    };
    vector<int> inorderTraversal(node *root)
    {
        vector<int> ans;
        node *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }

            else
            {
                // find the inorder predecessor
                node *ip = curr->left;
                while (ip->right != NULL && ip->right != curr)
                { // we are searching the rightmost node in the left subtree
                    ip = ip->right;
                }
                if (ip->right == NULL)
                {
                    ip->right = curr; // done the threading
                    curr = curr->left;
                }
                else
                {
                    ip->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }

                // morris algorithm does backtracking by storing the previous node value in inorder predecessor
                // it is in real miraclous
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    Solution::node *root1 = new Solution::node(1);
    root1->right = new Solution::node(2);
    root1->right->left = new Solution::node(3);
    vector<int> result1 = sol.inorderTraversal(root1);
    cout << "Test case 1: ";
    print1darray(result1);

    return 0;
}