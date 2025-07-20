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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;
    ListNode *mh = nullptr;
    ListNode *curr;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val < list2->val)
        {
            // hasn't started
            if (mh == nullptr)
            {
                curr = list1;
                mh = curr;
            }
            else
            {
                curr->next = list1;
                curr = curr->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (mh == nullptr)
            {
                curr = list2;
                mh = curr;
            }
            else
            {
                curr->next = list2;
                curr = curr->next;
            }
            list2 = list2->next;
        }
    }

    if (list1 != nullptr)
    {
        curr->next = list1;
    }
    else if (list2 != nullptr)
    {
        curr->next = list2;
    }

    return mh;
}

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

int main()
{
    int n, m;
    cin >> n >> m;

    int i = 0;
    ListNode *head1 = new ListNode(0);
    takeInputLL(head1, n);

    ListNode *head2 = new ListNode(0);
    takeInputLL(head2, m);

    printLL(head1);
    printLL(head2);
    
    cout << "----- MERGED LL -------" << endl;

    head1 = mergeTwoLists(head1, head2);
    printLL(head1);
    return 0;
}
