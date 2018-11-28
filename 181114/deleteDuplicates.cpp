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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *pre = start;
        while(pre->next) {
            ListNode *cur = pre->next;
            while(cur->next && cur->next->val == cur->val)
                cur = cur->next;
            if(cur != pre->next)
                pre->next = cur->next;
            else
                pre = pre->next;
        }
        return start->next;
    }
};