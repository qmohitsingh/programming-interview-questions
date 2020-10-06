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
    vector<int> nextLargerNodes(ListNode* head) {
        
        stack<int> stk;
        
        vector<int> res;
        
        while(head) {
            res.push_back(head->val);
            head = head->next;
        }
        
        vector<int> output(res.size(), 0);
        for (int i=0; i<res.size(); i++) {
            
            while(!stk.empty() && res[stk.top()] < res[i]) {
                output[stk.top()] = res[i];
                stk.pop();
            }
            
            stk.push(i);
            
        }
        
        return output;
        
    }
};
