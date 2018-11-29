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
        if (!head) return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* previous = newHead;
        ListNode* current = previous->next;
        while (current) {
            while (current->next && current->val == current->next->val) {
                current = current->next;
            }
            previous->next = current;
            previous = previous->next;
            current = current->next;
        }
        ListNode* answer = newHead->next;
        delete(newHead);
        return answer;
    }
};