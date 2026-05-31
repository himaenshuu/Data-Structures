#ifndef UTILITIES_H
#define UTILITIES_H
#include <climits>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

inline TreeNode *buildTree(const vector<int> &values, int nullValue = INT_MIN)
{
    if (values.empty() || values[0] == nullValue)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < values.size())
    {
        TreeNode *node = q.front();
        q.pop();

        if (i < values.size() && values[i] != nullValue)
        {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;

        if (i < values.size() && values[i] != nullValue)
        {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

inline void deleteTree(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

inline void print1darray(vector<int> vect)
{
    for (auto &el : vect)
    {
        cout << el << " ";
    }
    cout << "\n";
}

inline void print2darray(vector<vector<int>> vect)
{
    for (auto &row : vect)
    {
        for (auto &el : row)
        {
            cout << el << " ";
        }
        cout << "\n";
    }
}

#endif
