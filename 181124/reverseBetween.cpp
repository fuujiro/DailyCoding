/*================================================================
 * Copyright (C) 2018 by fuujiro. All rights reserved.
 *
 * Filename: reverseBetween.cpp
 * Contributor: fuujiro
 * Date: 12/12/2018
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
    ListNode* reverseBetween(ListNode* head,int m,int n){
        int reverse_len=n-m+1;
        ListNode *prehead=NULL;//记录第m-2号节点
        ListNode *new_reverse_tail=NULL;//记录第m-1号节点
        ListNode *next=NULL;
        ListNode *new_reverse_head=NULL; //记录第n-1号节点
        ListNode *result=head;
        while(head&&m>1){
            prehead=head;
            head=head->next;
            m--;
        }
        new_reverse_tail=head;
        while(head&&reverse_len>0){
            next=head->next;
            head->next=new_reverse_head;
            new_reverse_head=head;
            head=next;
            reverse_len--;
        }
        if(new_reverse_tail!=NULL) new_reverse_tail->next=head;
        if(prehead){
            prehead->next=new_reverse_head;
        }
        else {
            result=new_reverse_head;
        }
        return result;
    }
};
