/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head  == NULL || k <= 0)
            return head;
        ListNode *temp = head;
        int node_count = 0;
        while(temp != NULL) {
            node_count++;
            temp = temp->next;
        }
        if(k > node_count)
            k = k % node_count;
        if(k == node_count || k == 0)
            return head;
        //first node move k step
        ListNode *first = head;
        while(k > 0) {
            first = first->next;
            k--;
        }
        //when first node move to last, the second node move (length - k) step
        ListNode *second = head;
        while(first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        ListNode *newhead = second->next;
        //be a circle
        first->next = head;
        //broken circle
        second->next = NULL;
        return newhead;
    }
};