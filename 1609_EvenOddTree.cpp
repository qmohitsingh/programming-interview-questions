https://leetcode.com/problems/even-odd-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isEvenOddTree(TreeNode* root) {
        
        if (root == nullptr) return true;
        
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {root->val, 0}});
        
        while(!q.empty()) {
            pair<TreeNode*, pair<int,int>> temp = q.front();
            q.pop();
            
            if ((temp.second.first%2 == 0 && temp.second.second%2 == 0 ) || (temp.second.first%2 == 1 && temp.second.second%2 == 1)) {
                return false;
            }
            
          
            if (temp.first->left)
                q.push({temp.first->left, {temp.first->left->val, temp.second.second + 1}});
            if (temp.first->right)
                q.push({temp.first->right, {temp.first->right->val, temp.second.second + 1}});
            
            if (q.size() && temp.second.first >= q.front().second.first && temp.second.second == q.front().second.second &&  q.front().second.second%2 == 0) {
                return false;   
            }
            
            if (q.size() && temp.second.first <= q.front().second.first && temp.second.second == q.front().second.second &&  q.front().second.second%2 == 1) {
                return false;   
            }
            
        }
        
        return true;
    }
};
