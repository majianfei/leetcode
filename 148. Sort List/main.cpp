#include <iostream>

/**
 * Runtime: 44 ms, faster than 96.33% of C++ online submissions for Sort List.
 * Memory Usage: 11.7 MB, less than 77.27% of C++ online submissions for Sort List.
*/
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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)return head;
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* right = sortList(slow->next);
        slow->next = NULL;
        ListNode* left = sortList(head);
        return merge(left, right);
    }
    
    ListNode *merge(ListNode* left, ListNode* right){
        ListNode dummy(0),*node;
        node = &dummy;
        while (left && right){
            if (left->val < right->val){
                node->next = left;
                left = left->next;
            }
            else{
                node->next = right;
                right = right->next;
            }
            node = node->next;
        }
        if (left)node->next = left;
        else node->next = right;
        return dummy.next;
    }
};