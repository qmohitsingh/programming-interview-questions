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
    int max_path_sum ;
    int maxPathSum(TreeNode* root) {
        max_path_sum = INT_MIN;
        recursion(root);
        
        return max_path_sum;
    }
    
    int recursion(TreeNode* root) {
        
        if (!root) return 0;
        
        int left = max(0, recursion(root->left));
        int right = max(0, recursion(root->right));
        max_path_sum = max(max_path_sum, left+right+root->val);
        return max(left, right) + root->val;
    } 
    
};
