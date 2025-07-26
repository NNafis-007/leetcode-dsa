#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLL(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "\n";
}

// --------- ITERATIVE -----------
ListNode *reverseList(ListNode*& head)
{
    if (!head || !head->next)
        return head;
    ListNode *l = nullptr;
    ListNode *r = head->next;
    while (r != nullptr)
    {
        head->next = l;
        l = head;
        head = r;
        r = r->next;
    }
    // everything except last node done
    head->next = l;
    return head;
}

// // ----- RECURSIVE ------
// void helper(ListNode* l, ListNode*& m, ListNode* r)
// {
//     m->next = l;
//     if (!r)
//         return;
//     l = m;
//     m = r;
//     r = r->next;
//     helper(l, m, r);
// }

// ListNode *reverseList(ListNode *head)
// {
//     if (!head)
//         return head;
//     helper(nullptr, head, head->next);
//     return head;
// }

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *h2 = new ListNode(2);
    ListNode *h3 = new ListNode(3);
    ListNode *h4 = new ListNode(4);
    ListNode *h5 = new ListNode(5);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = NULL;
    printLL(head);
    reverseList(head);
    printLL(head);
    return 0;
}
