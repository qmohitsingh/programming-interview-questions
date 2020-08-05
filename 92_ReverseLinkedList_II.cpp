
//Problem Description

/*
92. Reverse Linked List II (Medium)

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if (!head) return NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(m > 1) {
            prev = curr;
            curr = curr->next;
            m--;
            n--;
        }
        
        ListNode* start = prev; 
        ListNode* tail = curr;
        while(n > 0) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            n--;
        }
        
        if (!start) {
            head = prev;
        } else {
            start->next = prev;
        }
        
        tail->next = curr;
        
        return head;
    }
};
