// Remove nth node from the back of the linked list

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

struct node
{
    int val;
    struct node *next;
    node(int v = 0) : val(v), next(nullptr) {}
};

class Solution
{
public:
    node *removeNthNodeFromTheFront(node *head, int n)
    {
        node *ptr = head;
        if (n == 1)
            return head = head->next;

        for (int i = 2; i < n; i++)
        {
            ptr = ptr->next;
            if (!ptr) // cases where the n> size of the linkedin list
                return NULL;
        }
        ptr->next = ptr->next->next;

        return head;
    }

    node *removeNthNodeFromTheBack(node *head, int n)
    {
        return head;
    }
};

// Build a linked list from a vector
node *buildList(const vector<int> &vals)
{
    node *dummy = new node(-1);
    node *ptr = dummy;
    for (int v : vals)
    {
        ptr->next = new node(v);
        ptr = ptr->next;
    }
    return dummy->next;
}

// Print a linked list
void printList(node *head)
{
    if (!head)
    {
        cout << "NULL" << endl;
        return;
    }
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Example 1: [1,2,4] + [1,3,4] => [1,1,2,3,4,4]
    node *l1 = buildList({1, 2, 4});
    node *l2 = buildList({1, 3, 4});
    cout << "Example 1: ";
    printList(sol.removeNthNodeFromTheFront(l1, 2)); // 1 -> 1 -> 2 -> 3 -> 4 -> 4

    // Example 2: [] + [] => NULL
    node *l3 = buildList({});
    node *l4 = buildList({});
    cout << "Example 2: ";
    // printList(sol.mergeTwoLists(l3, l4)); // NULL

    // Example 3: [] + [0] => [0]
    node *l5 = buildList({});
    node *l6 = buildList({0});
    cout << "Example 3: ";
    // printList(sol.mergeTwoLists(l5, l6)); // 0

    return 0;
}