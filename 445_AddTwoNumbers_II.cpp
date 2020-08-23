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
    
    ListNode* reverse(ListNode* l) {
        
        ListNode* root = l;
        ListNode* prev = NULL;
        
        while(root) {
            ListNode* next = root->next;
            root->next = prev;
            prev = root;
            root = next;
        }
        
        return prev;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (!l1) return l2;
        
        if (!l2) return l1;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* root = dummy;
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int r = 0;
        while(l1 || l2) {
            
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            
            int sum  = (val1 + val2 + r);
            
            r = (sum)/10;
            
            dummy->next = new ListNode(sum%10);
            
            dummy = dummy->next;
            
            if (l1) {
                l1 = l1->next;
            }
            
            if (l2) {
                l2 = l2->next;
            }
        
        }
        
        if (r) {
            dummy->next = new ListNode(r);
            dummy = dummy->next;
        }
        
        root = reverse(root->next);
        
        return root;
        
    }
};
