#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct Node *root, vector<int> &vec)
{
    if (root == NULL)
        return;
    vec.push_back(root->data);
    preorder(root->left, vec);
    preorder(root->right, vec);
}

void inorder(struct Node *root, vector<int> &vec)
{
    if (root == NULL)
        return;
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

void postorder(struct Node *root, vector<int> &vec)
{
    if (root == NULL)
        return;
    postorder(root->left, vec);
    postorder(root->right, vec);
    vec.push_back(root->data);
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(9);
    root->right->right = new Node(14);

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    
    preorder(root, v1);
    inorder(root, v2);
    postorder(root, v3);

    cout << "Preorder traversal: ";
    for (auto &el : v1)
    {
        cout << el << " ";
    }
    cout << "\nInorder traversal: ";
    for (auto &el : v2)
    {
        cout << el << " ";
    }
    cout << "\nPostorder traversal: ";
    for (auto &el : v3)
    {
        cout << el << " ";
    }

    return 0;
}