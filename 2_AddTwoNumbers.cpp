/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* l3 = new ListNode(-1);
        ListNode* res = l3;
        
        int r = 0;
        while(l1 || l2) {
            
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            
            int sum = val1 + val2 + r;
            
            r = sum/10;
            
            l3->next = new ListNode(sum%10);
            
            l3 = l3->next;
        
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        
        }
        
        if (r) {
            l3->next = new ListNode(r);
        }
        
        
        return res->next;
        
    }
};
