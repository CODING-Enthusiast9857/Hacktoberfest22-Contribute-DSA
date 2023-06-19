/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        if(node.next==null)
        {
            return;
        }
        ListNode curr=node;
        ListNode prev=null;
        while(curr.next!=null)
        {
            curr.val=curr.next.val;
            prev=curr;
            curr=curr.next;
        }
        prev.next=null;
    }
}
