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
Given the root of a binary tree, return the level order traversal of its nodes'
values. Print the nodes level by level from left to right.

Difficulty:
Medium

Companies commonly asked:
Amazon, Microsoft, Google, Apple, Meta, Adobe, Oracle, Bloomberg, Uber, Walmart

Entry level importance:
High. This is a classic breadth-first search tree problem and is a common
interview question for understanding queues and level-wise processing.

Optimal approach used:
Breadth-first search using a queue. Process nodes level by level by tracking the
current queue size, collecting values for each level, and pushing children for
the next level.

Time Complexity:
O(n), where n is the number of nodes in the tree.
Space Complexity:
O(w), where w is the maximum width of the tree.
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // approach - push the root node in a queue, then
        // pop it until it becomes empty, inbetween also
        // run the second loop for the size of queue
        // 1- push the value of node in a 1d vector
        // 2- push the left and right nonNull node in the queue
        // 3- after the second loop ends push the 1d vector to 2d vector
        // return the ans

        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> vect;
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                vect.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }
            ans.push_back(vect);
        }
        return ans;
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

    cout << "Test case 1 level order:" << endl;
    print2darray(sol.levelOrder(root));

    return 0;
}