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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for (auto& list : lists) {
            if (list) pq.emplace(list);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            curr->next = top;
            if (top->next) pq.emplace(top->next);
            curr = curr->next;
        }
        return dummy->next;
    }
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};
