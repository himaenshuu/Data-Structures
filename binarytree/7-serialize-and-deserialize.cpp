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
class Codec
{
public:
    vector<string> split(string str)
    {
        vector<string> ans;
        string s = "";
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ',')
            {
                ans.push_back(s);
                s = "";
            }
            else
                s += str[i];
        }

        ans.push_back(s);
        return ans;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        vector<string> S;
        string ans;
        if (!root)
            return "";

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (!temp)
                {
                    S.push_back("#");
                    continue;
                }
                else
                    S.push_back(to_string(temp->val));

                q.push(temp->left);
                q.push(temp->right);
            }
        }

        // convert it to a plane string seperated by comma
        for (int i = 0; i < S.size(); i++)
        {
            ans += S[i];
            if (i < S.size() - 1)
                ans += ',';
        }
        // return the final string
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return NULL;

        vector<string> newData = split(data); // this will contain without comma
        TreeNode *root = new TreeNode(stoi(newData[0]));

        queue<TreeNode *> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < newData.size())
        {
            TreeNode *parent = q.front();
            q.pop();

            if (i < newData.size() && newData[i] != "#")
                parent->left = new TreeNode(stoi(newData[i]));
            i++;

            if (i < newData.size() && newData[i] != "#")
                parent->right = new TreeNode(stoi(newData[i]));
            i++;

            if (parent->left)
                q.push(parent->left);
            if (parent->right)
                q.push(parent->right);
        }

        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}