/*================================================================
 * Copyright (C) 2018 by fuujiro. All rights reserved.
 *
 * Filename: partition.cpp
 * Contributor: fuujiro
 * Date: 12/02/2018
 * Description:
*
================================================================*/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode res(0), mid(0);
        if(!head)
            return NULL;
        ListNode* small = &res;
        ListNode* big = &mid;
        while(head) {
            if(head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }
        big->next = NULL;
        small->next = mid.next;
        return res.next;
    }
};
