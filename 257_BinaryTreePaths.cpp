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
    
    void dfs(TreeNode* root, vector<string>& res, string str) {
        
        if(root == NULL) {
            return;
        }
        
        str = 
            str.length() == 0 
            ? str + to_string(root->val) 
            : str + "->"+ to_string(root->val);
        
        if (!root->left && !root->right) {
            res.push_back(str);
            return;
        }
        
        //cout<<"str :"<<str<<endl;
        dfs(root->left, res, str);
        dfs(root->right, res, str);
        
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res;
        
        dfs(root, res, "");
        
        return res;
        
    }
};
