class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int l=0;
        ListNode *p=head;
        
        while(p!=nullptr)
        {
            l++;
            p=p->next;
        }
        l=l-n;
        if(l==0)
        {
            head=head->next;
            return head;
        }
        p=head;
        for(int i=0;i!=l-1;i++)
        {
            p=p->next;
        } 
        p->next=p->next->next;
        return head;
    }
};
