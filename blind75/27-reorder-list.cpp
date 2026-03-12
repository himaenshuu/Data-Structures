/*
Problem Statement:
Given the head of a singly linked list L0 -> L1 -> ... -> Ln,
reorder it to L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
without changing node values.

Difficulty Level:
Medium

Top Companies Asked:
Amazon, Microsoft, Meta, Google, Bloomberg

Entry-Level Importance (0-2 YoE): 3/5

Early Intuition:
Take nodes alternately from the start and end. Since singly linked lists do not support backward traversal, reverse the second half first.

Optimal Approach:
1) Find middle using slow/fast pointers.
2) Split list into two halves.
3) Reverse second half.
4) Merge first half and reversed second half alternately.
Time: O(N), Space: O(1)

Pseudo-code:
find mid using slow/fast
second = slow.next, slow.next = null
second = reverse(second)
first = head
while second:
    save firstNext, secondNext
    first.next = second
    second.next = firstNext
    first = firstNext
    second = secondNext
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
    int findMid(node *head)
    {
        int mid = 0;

        node *slow = head;
        node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            mid++;
        }

        slow = reverseLL(slow); // reverse after slow to end

        return slow->val;
    }

    node *ReorderLL(node *head)
    {
        // find the mid
        // traverse the slow pointer to mid
        // break the ll to 2 part with null at end
        // reverse the LL from the second half;
        // merge the two alternatively

        // if(head->)

        node *slow = head;
        node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        node *secondHalf = slow->next;
        slow->next = nullptr;         // slow is now last of first half
        slow = reverseLL(secondHalf); // reverse only the second half

        // merge two halves alternatively
        node *ptr = head;
        node *temp = slow;

        while (temp)
        {
            node *nextPtr = ptr->next;   // points 1 ahead of ptr
            node *nextTemp = temp->next; // pointes 1 ahead of slow pointer

            ptr->next = temp;
            temp->next = nextPtr;

            ptr = nextPtr; // Increment the ptr and temp positions
            temp = nextTemp;
        }

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
    node *l1 = buildList({1, 2, 3, 4});
    cout << "Test 1: ";
    printList(sol.ReorderLL(l1)); // 1 -> 4 -> 2 -> 3

    node *l2 = buildList({1, 2, 3, 4, 5});
    cout << "Test 2: ";
    printList(sol.ReorderLL(l2)); // 1 -> 5 -> 2 -> 4 -> 3

    node *l3 = buildList({10, 20});
    cout << "Test 3: ";
    printList(sol.ReorderLL(l3)); // 10 -> 20

    return 0;
}