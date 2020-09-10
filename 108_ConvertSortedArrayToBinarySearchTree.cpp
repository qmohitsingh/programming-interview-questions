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
    TreeNode* constructBinaryTreeFromArray(vector<int> & nums, int left, int right) {
        
        if (left > right) return NULL;
        
        int mid = left + (right-left)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left  = constructBinaryTreeFromArray(nums, left, mid-1);
        node->right = constructBinaryTreeFromArray(nums, mid+1, right);
        return node;
        
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0) return NULL;
        
        return constructBinaryTreeFromArray(nums, 0, nums.size()-1);
    }
};
