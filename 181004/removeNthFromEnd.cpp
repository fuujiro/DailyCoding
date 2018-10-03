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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* slow = start;
        ListNode* fast = start;
        for(int i = 0; i < n + 1; ++i) {
            fast = fast->next;
        }
        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
};
