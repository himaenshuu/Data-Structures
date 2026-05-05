#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

/*
Problem Statement:
Given the root of a binary tree, return the preorder, inorder, and postorder
traversals of the tree.

Preorder traversal visits nodes in the order: root, left subtree, right subtree.
Inorder traversal visits nodes in the order: left subtree, root, right subtree.
Postorder traversal visits nodes in the order: left subtree, right subtree, root.

Difficulty:
Easy

Companies commonly asked:
Amazon, Microsoft, Google, Apple, Meta, Adobe, Oracle, Bloomberg, Uber, Walmart

Entry level importance:
High. Tree traversals are foundational and frequently used to test recursion,
pointer handling, and understanding of binary tree structure.

Optimal approach used:
Recursive DFS traversal for each order. The code visits the nodes in the exact
required order and appends each value to the corresponding vector.

Time Complexity:
O(n) for each traversal, where n is the number of nodes in the tree.
Space Complexity:
O(h) recursion stack space, where h is the height of the tree.
*/
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

void printVector(const vector<int> &vec)
{
    for (auto &el : vec)
    {
        cout << el << " ";
    }
    cout << endl;
}

void runTestCase(int caseNo, Node *root)
{
    vector<int> v1, v2, v3;
    preorder(root, v1);
    inorder(root, v2);
    postorder(root, v3);

    cout << "Test case " << caseNo << endl;
    cout << "Preorder traversal: ";
    printVector(v1);
    cout << "Inorder traversal: ";
    printVector(v2);
    cout << "Postorder traversal: ";
    printVector(v3);
    cout << endl;
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

    runTestCase(1, root);

    return 0;
}
