#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

/*
 * ============================================================
 *  Problem  : Merge Two Sorted Lists (LeetCode #21)
 *  Difficulty: Easy
 * ============================================================
 *  Statement:
 *    You are given the heads of two sorted (ascending) singly
 *    linked lists, list1 and list2.
 *    Merge the two lists into one sorted linked list and return
 *    the head of the merged list.
 *    The merged list should be formed by splicing together the
 *    nodes of the first two lists (not creating new nodes).
 *
 *  Examples:
 *    Input : list1 = [1,2,4], list2 = [1,3,4]
 *    Output: [1,1,2,3,4,4]
 *
 *    Input : list1 = [], list2 = []
 *    Output: []
 *
 *    Input : list1 = [], list2 = [0]
 *    Output: [0]
 *
 *  Constraints:
 *    - Number of nodes in each list is in range [0, 50].
 *    - -100 <= Node.val <= 100
 *    - Both lists are sorted in non-decreasing order.
 *
 *  Approach: Two-pointer / Iterative with a dummy head
 *    1. Create a dummy node to act as the pre-head of the result.
 *    2. Use a pointer `ptr` that always points to the last node
 *       of the merged list built so far.
 *    3. Compare the front nodes of list1 and list2; attach the
 *       smaller one to ptr->next and advance that list's pointer.
 *    4. After one list is exhausted, attach the remainder of the
 *       other list directly (no need to iterate — it's already sorted).
 *    5. Return dummy->next.
 *
 *  Time  : O(m + n)  — each node is visited once.
 *  Space : O(1)      — only pointer manipulation, no extra storage.
 * ============================================================
 */

struct node
{
    int val;
    struct node *next;
    node(int v = 0) : val(v), next(nullptr) {}
};

class Solution
{
public:
    node *mergeTwoLists(node *list1, node *list2)
    {
        node *head = new node(-1); // dummy node
        node *ptr = head;

        while (!list1 && !list2)
        {
            return NULL;
        }

        while (list1 && list2)
        {
            node *temp = new node();
            if (list1->val < list2->val)
            {
                ptr->next = list1;
                list1 = list1->next;
            }
            else
            {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }

        if (list1)
        {
            ptr->next = list1;
        }
        else
        {
            ptr->next = list2;
        }

        return head->next;
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
    printList(sol.mergeTwoLists(l1, l2)); // 1 -> 1 -> 2 -> 3 -> 4 -> 4

    // Example 2: [] + [] => NULL
    node *l3 = buildList({});
    node *l4 = buildList({});
    cout << "Example 2: ";
    printList(sol.mergeTwoLists(l3, l4)); // NULL

    // Example 3: [] + [0] => [0]
    node *l5 = buildList({});
    node *l6 = buildList({0});
    cout << "Example 3: ";
    printList(sol.mergeTwoLists(l5, l6)); // 0

    return 0;
}