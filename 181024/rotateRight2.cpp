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
    ListNode *getLastNode(ListNode *head, int& len) {
        ListNode *node = head;
        len = 1;
        if(head == NULL) {
            len = 0;
            return NULL;
        }
        while(node->next != NULL) {
            node = node->next;
            len++;
        }
        return node;
    }
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL) {
            return head;
        }
        int len;
        ListNode *lastNode = getLastNode(head, len);
        lastNode->next = head;

        k %= len;
        int step = len - k;
        while(step > 0) {
            lastNode = lastNode->next;
            step--;
        }
        head = lastNode->next;
        lastNode->next = NULL;
        return head;
    }
};