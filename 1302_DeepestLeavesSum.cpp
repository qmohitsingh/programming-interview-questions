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
    int deepestLeavesSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int levelSum = 0;
        
        while(!q.empty()) {
            
            levelSum = 0;
            
            int size = q.size();
            for (int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                levelSum += temp->val;
            
                if (temp->left)
                    q.push(temp->left);
                
                if (temp->right)
                    q.push(temp->right);
                
            }            
            
        }
        return levelSum;
        
    }
};
