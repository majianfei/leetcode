#include <stdio.h>


/**
 * Definition for singly-linked list.
 */ 
 struct ListNode {
     int val;
     struct ListNode *next;
 };

/**
 * Runtime: 8 ms, faster than 99.52% of C online submissions for Add Two Numbers.
 * Memory Usage: 8.9 MB, less than 84.83% of C online submissions for Add Two Numbers.
 */ 

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1==NULL)return l2;
    else if(l2==NULL)return l1;
    struct ListNode* head = NULL, *cur = NULL;
    int add = 0, num1 = 0, num2=0;
    while(l1||l2||add>0){
        num1 = (l1==NULL)?0:l1->val;
        num2 = (l2==NULL)?0:l2->val;
        int tmp = num1+num2+add;
        add = tmp/10;
        
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = tmp%10;
        node->next = NULL;
        if (head == NULL)head=node;
        else {
            cur->next = node;
        }
        cur = node;
        
        if (l1)l1=l1->next;
        if (l2)l2=l2->next;
    }
    return head;
}