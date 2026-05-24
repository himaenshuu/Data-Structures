#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

struct node
{
    int val;
    struct node *next;
};

bool checkpalindrome(node *head)
{
    node *left = head;
    node *right = head;

    int count = 1;
    while (right->next)
    {
        count++;
        right = right->next;
    }
    count = count / 2;
    while (count--)
    {
    }
}

node *addTwoNumbers(node *l1, node *l2)
{
    node *ptr1 = l1;
    node *ptr2 = l2;
    node *head = new node();
    int carry = 0, sum = 0;
    sum = ptr1->val + ptr2->val;
    head->val = sum % 10;
    head->next = NULL;
    carry = sum / 10;
    ptr2 = ptr2->next;
    ptr1 = ptr1->next;

    node *ptr3 = head;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        sum = ptr1->val + ptr2->val + carry;
        node *temp = new node();
        temp->next = NULL;
        temp->val = sum % 10;
        temp->next = NULL;
        ptr3->next = temp;
        ptr3 = ptr3->next;
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
        carry = sum / 10;
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            node *temp = new node();
            sum = ptr2->val + carry;
            temp->val = sum % 10;
            temp->next = NULL;
            ptr3->next = temp;
            ptr3 = ptr3->next;
            carry = sum / 10;
            ptr2 = ptr2->next;
        }
    }

    if (ptr2 == NULL)
    {
        while (ptr1)
        {
            node *temp = new node();
            sum = ptr1->val + carry;
            temp->val = sum % 10;
            temp->next = NULL;
            ptr3->next = temp;
            ptr3 = temp;
            carry = sum / 10;
            ptr1 = ptr1->next;
        }
    }

    if (carry != 0)
    {
        node *temp = new node();
        temp->val = carry;
        temp->next = NULL;
        ptr3->next = temp;
    }

    return head;
}

struct node *deletenthnode(node *head, int n)
{
    node *ptr = head;
    int count = 0;

    if (!head)
        return NULL;

    while (ptr->next)
    {
        ptr = ptr->next;
        count++;
    }

    int pos = count - n + 1;
    ptr = head;
    int i = 0;
    if (pos == 1)
    {
        node *temp = ptr;
        ptr = ptr->next;
        delete ptr;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }

        node *temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
    }
    return head;
}

struct node *deletenthnode1(node *head, int n) // Two pointer approach in a single pass
{
    if (!head)
        return NULL;
    node *ptr1 = head;
    node *ptr2 = head;

    for (int i = 0; i < n; i++)
    {
        if (!ptr2)
            return head;
        ptr2 = ptr2->next;
    }

    if (!ptr2)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while (ptr2->next)
    {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    node *temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    delete temp;

    return head;
}

struct node *addelementsll1(struct node *head)
{
    int x;
    cout << "Enter zero to escape otherwise positive" << endl;

    if (!head)
    {
        cin >> x;
        if (x == 0)
            return head;

        head = new node();
        head->val = x;
        head->next = NULL;
    }
    node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    while (1)
    {
        cin >> x;
        if (x == 0)
            break;
        node *temp = new node();
        temp->val = x;
        temp->next = NULL;
        ptr->next = temp;
        ptr = ptr->next;
    }
    return head;
}

void showll(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    head1 = addelementsll1(head1);
    cout << "First number is : ";
    showll(head1);
    cout << endl;
    head2 = addelementsll1(head2);
    cout << "Second number is : ";
    showll(head2);
    cout << endl;
    node *head3 = NULL;

    head3 = addTwoNumbers(head1, head2);
    cout << "Addition of number is :";
    showll(head3);
    return 0;
}

// ListNode *ptr1 = l1;
// ListNode *ptr2 = l2;
// ListNode *head = new ListNode();
// int carry = 0, sum = 0;
// sum = ptr1->val + ptr2->val;
// head->val = sum % 10;
// head->next = NULL;
// carry = sum / 10;
// ptr2 = ptr2->next;
// ptr1 = ptr1->next;

// ListNode *ptr3 = head;

// while (ptr1 != NULL && ptr2 != NULL)
// {
//     sum = ptr1->val + ptr2->val + carry;
//     ListNode *temp = new ListNode();
//     temp->next = NULL;
//     temp->val = sum % 10;
//     temp->next = NULL;
//     ptr3->next = temp;
//     ptr3 = ptr3->next;
//     ptr2 = ptr2->next;
//     ptr1 = ptr1->next;
//     carry = sum / 10;
// }
// if (ptr1 == NULL)
// {
//     while (ptr2 != NULL)
//     {
//         ListNode *temp = new ListNode();
//         sum = ptr2->val + carry;
//         temp->val = sum % 10;
//         temp->next = NULL;
//         ptr3->next = temp;
//         ptr3 = ptr3->next;
//         carry = sum / 10;
//         ptr2 = ptr2->next;
//     }
// }

// if (ptr2 == NULL)
// {
//     while (ptr1)
//     {
//         ListNode *temp = new ListNode();
//         sum = ptr1->val + carry;
//         temp->val = sum % 10;
//         temp->next = NULL;
//         ptr3->next = temp;
//         ptr3 = ptr3->next;
//         carry = sum / 10;
//         ptr1 = ptr1->next;
//     }
// }
// return head;
