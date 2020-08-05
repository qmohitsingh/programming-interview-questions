class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        
        //Iterative approach
//         if (head == NULL) return head;
        
//         ListNode* prev = NULL;
        
//         while(head != NULL) {
//             ListNode* next = head->next;
//             head->next = prev;
//             prev = head;
//             head = next;
//         }
        
//         return prev;
        
        //Recusive approach
        stack<ListNode*> stk;
        
        while(head) {
            stk.push(head);
            head = head->next;
        }
        
        ListNode* dummy = new ListNode(-1);
        head = dummy;
        
        while(!stk.empty()) {
            ListNode* temp = stk.top();
            stk.pop();
            
            dummy->next = new ListNode(temp->val);
            
            dummy = dummy->next;
            
        }
        
        return head->next;
    }
};
