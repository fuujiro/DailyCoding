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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto node = head;
        for(int i = 0; i < k; ++ i) {
            if(!node) return head;
            node = node->next;
        }

        auto new_head = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return new_head;        
    }

    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* head = end;

        while(start != end) {
            auto temp = start->next;
            start->next = head;
            head = start;
            start = temp;
        }

        return head;
    }
};
