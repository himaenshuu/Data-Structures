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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool trav(TreeNode *root, int tS, vector<int> arr, vector<vector<int>> &bigArr)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)
        {
            if (tS == root->val)
            {
                arr.push_back(root->val);
                bigArr.push_back(arr);
                return true;
            }
            return false;
        }
        int rSum = tS - root->val;
        arr.push_back(root->val);
        return trav(root->left, rSum, arr, bigArr) + trav(root->right, rSum, arr, bigArr);
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return {};
        vector<vector<int>> bigArr;
        vector<int> arr;
        trav(root, targetSum, arr, bigArr);
        return bigArr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution sol;
   
    print2d(sol.pathSum(root, 22));

    return 0;
}