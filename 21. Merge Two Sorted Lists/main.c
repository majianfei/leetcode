#include <stdio.h>

/**
 * Runtime: 0 ms, faster than 100.00% of C online submissions for Merge Two Sorted Lists.
 * Memory Usage: 7.5 MB, less than 63.53% of C online submissions for Merge Two Sorted Lists.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* header = NULL;
    struct ListNode* cur = NULL;
    
    if (l1 == NULL)return l2;
    else if(l2 == NULL)return l1;
    
    while(l1 && l2){
        if (l1->val > l2->val){
            if (cur == NULL)cur = l2;
            else {
                cur->next = l2;
                cur = cur->next;
            }
            l2 = l2->next;
        }
        else{
            if (cur == NULL)cur = l1;
            else{
                cur->next = l1;
                cur = cur->next;
            }
            l1 = l1->next;
        }
        if (header == NULL)header = cur;
    }
    
    if (l1 != NULL)cur->next = l1;
    else if (l2 != NULL)cur->next = l2;
    return header;
}