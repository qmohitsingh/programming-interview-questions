
// space O(1), timp O(N)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
//         unordered_map<ListNode*, int> hashMap;
        
//         while(head && head->next) {
            
//             if(hashMap[head]) return head;
            
//             hashMap[head] = 1;
//             head = head->next;
            
//         }
        
//         return NULL;
        
        if (!head || !head->next) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
                break;
        }
        
        if (slow != fast) return NULL;
        
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};

// space O(N), timp O(N)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_map<ListNode*, int> hashMap;
        
        while(head && head->next) {
            
            if(hashMap[head]) return head;
            
            hashMap[head] = 1;
            head = head->next;
            
        }
        
        return NULL;
        
    }
};

