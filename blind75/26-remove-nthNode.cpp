/*
Problem Statement:
Given the head of a singly linked list, remove the n-th node from the end of the list and return the head of the updated list.

Difficulty Level:
Medium

Top Companies Asked:
Amazon, Microsoft, Meta, Google, Adobe

Entry-Level Importance (0-2 YoE): 4/5

Early Intuition:
If we know the total length of the list, we can convert "n-th from end" into "k-th from front" and remove that node safely.

Optimal Approach (Current Implementation):
1) Traverse once to compute list length.
2) Convert index: k = length - n + 1.
3) If k == 1, remove head.
4) Otherwise move to (k-1)-th node and relink next pointers.
Time: O(N), Space: O(1)

Pseudo-code:
length = count nodes
if n > length: return null (or unchanged based on convention)
k = length - n + 1
if k == 1: return head.next
move pointer to node at position (k - 1)
pointer.next = pointer.next.next
return head
*/

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
    node *reverseLL(node *head)
    {
        node *temp1 = NULL;
        node *temp2 = NULL;

        while (head)
        {
            temp2 = head->next;
            head->next = temp1;
            temp1 = head;
            head = temp2;
        }
        head = temp1;

        return head;
    }

    node *removeNthNodeFromTheFront(node *head, int n)
    {
        node *ptr = head;
        if (n == 1)
            return head = head->next;

        for (int i = 2; i < n; i++)
        {
            ptr = ptr->next;
            if (!ptr->next) // cases where the n> size of the linkedin list
                return NULL;
        }
        ptr->next = ptr->next->next;

        return head;
    }

    node *removeNthNodeFromTheBack(node *head, int n)
    {
        // First - find the size
        // Second - Calculate the exact position from the front
        // Third - traverse to 1 position before that, and do the operations
        int size = 0;
        node *ptr = head;

        while (ptr)
        {
            ptr = ptr->next;
            size++;
        }

        ptr = head;
        if (n > size)
            return NULL; // safety checks
        int N = size - (n - 1);

        if (N == 1)
            return head = head->next;

        for (int i = 2; i < N; i++)
        {
            ptr = ptr->next;
            if (!ptr->next) // cases where the n> size of the linkedin list
                return NULL;
        }

        ptr->next = ptr->next->next;
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
    node *l1 = buildList({1, 2, 3, 4, 5});
    cout << "Test 1 (remove 2nd from end): ";
    printList(sol.removeNthNodeFromTheBack(l1, 2)); // 1 -> 2 -> 3 -> 5

    node *l2 = buildList({1});
    cout << "Test 2 (single node, remove 1st from end): ";
    printList(sol.removeNthNodeFromTheBack(l2, 1)); // NULL

    node *l3 = buildList({10, 20, 30, 40});
    cout << "Test 3 (remove 4th from end): ";
    printList(sol.removeNthNodeFromTheBack(l3, 4)); // 20 -> 30 -> 40

    return 0;
}