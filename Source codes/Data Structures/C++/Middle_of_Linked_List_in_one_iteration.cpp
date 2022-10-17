#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while(fast!=NULL and fast->next!=NULL)
    {
        slow = slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main() {
    ListNode *head = new ListNode(3), *temp = head;
    temp->next = new ListNode(1);
    temp = temp->next;
    temp->next = new ListNode(-1);
    temp = temp->next;
    temp->next = new ListNode(10);
    temp = temp->next;
    temp->next = NULL;

    ListNode *cycle = middleNode(head);
    cout<<cycle->val;
    cout<<endl;
    return 0;
}