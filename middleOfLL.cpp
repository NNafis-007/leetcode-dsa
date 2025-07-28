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

void takeInputLL(ListNode *head, int size)
{
    ListNode *curr = head;
    int i = 0;
    while (i < size)
    {
        int x;
        cin >> x;
        if (i == 0)
        {
            head->val = x;
        }
        else
        {
            curr->next = new ListNode(x);
            curr = curr->next;
        }
        i++;
    }
}


// Solution using fast and slow pointer
ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        // cout << "Fast at " << fast->val << endl;
        // cout << "head at " << head->val << endl;
        fast = fast->next->next;
        head = head->next;
    }
    return head;
}