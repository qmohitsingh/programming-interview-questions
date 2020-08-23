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
    
    ListNode* reverserLinkedList(ListNode* head, int k) {
        
        if (head == NULL) return head;
        
        ListNode* prev = NULL;
        
        while(head && k--) {
            
            ListNode* next = head->next;
            
            //cout<<"val: "<<next->val<<endl;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* root = new ListNode(0,  head);
        
        ListNode* curr = head;
        ListNode* prev = root;
        
        while(curr) {
            ListNode* tail = curr;
            
            int listIndex = 0;
            
            while(curr && listIndex < k) {
                curr = curr->next;
                listIndex++;
            }
            
            if (listIndex != k) {
                 prev->next = tail;
            } else {
                prev->next = reverserLinkedList(tail, k);
                prev = tail;
            }
            
        }
        
        return root->next;
    }
};
