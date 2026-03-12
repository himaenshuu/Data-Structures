/*
Problem: Reverse Linked List (LeetCode #206)
Difficulty: Easy
Top Companies: Amazon, Microsoft, Meta, Google, Apple, Adobe
Entry-Level Importance (0-2 YoE): 5/5

Problem Statement:
Given the head of a singly linked list, reverse the list and return the new head.

Early Intuition:
Use three pointers: prev (starts null), curr (starts at head), next (temp).
For each node, save next, redirect curr->next to prev, then advance all three.
After the loop, prev points to the new head.

Optimal Approach:
Iterative three-pointer reversal. No extra data structures.
prev=null, curr=head; while curr: next=curr->next, curr->next=prev, prev=curr, curr=next.
Return prev. Time: O(n), Space: O(1).
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
};

class Solution
{
public:
    struct node *mergeTwoLists(node *list1, node *list2)
    {
        node *head = NULL;
        node *ptr = NULL;

        while (list1 && list2)
        {
            node *temp = new node();
            if (list1->val < list2->val)
            {
                temp->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                temp->val = list2->val;
                list2 = list2->next;
            }
            if (!head)
            {
                ptr = head = temp;
            }
            ptr = temp;
            ptr = ptr->next;
        }

        while (list1)
        {
            node *temp = new node();
            temp->val = list1->val;
            list1 = list1->next;
        }

        while (list2)
        {
            node *temp = new node();
            temp->val = list2->val;
            list2 = list2->next;
        }

        return head;
    }

    bool checkIfCircular(struct node *head)
    {
        node *ptr = head;
        node *slow = head;
        node *fast = head->next;

        while (slow)
        {
            if (slow->val == fast->val)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }

    struct node *reverseLL(struct node *head)
    {
        struct node *temp1 = NULL;
        struct node *temp2 = NULL;

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

    void showLL(struct node *head)
    {
        cout << "the numbers are : ";
        node *ptr = head;
        while (ptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
    }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // Insert the element

    node *head = NULL;
    node *ptr = head;
    int x;
    cout << "Enter number 0 to escape :\n";
    while (cin >> x && x != 0)
    {
        node *temp = new node();
        temp->val = x;
        temp->next = NULL;
        if (!ptr) // if ptr is NULL
        {
            head = ptr = temp;
            continue;
        }
        ptr->next = temp;
        ptr = ptr->next;
    }
    Solution sol;

    sol.showLL(head);
    head = sol.reverseLL(head);
    sol.showLL(head);

    return 0;
}