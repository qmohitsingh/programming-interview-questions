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
    
    map<int, set<pair<int,int>>> posMap;  

    void helper (TreeNode* node, int x, int y) {
        if (node == NULL) return;
        posMap[x].insert({y,node->val}); //Push using x-coord as key and pair {y-coord, val} in the set

        // Calculate the x and y coords of left and right child
        // Hack for y coord (used y+1 instead of y-1) for set to sort pairs correctly
        int left_x = x-1;
        int left_y = y+1;
        int right_x = x+1;
        int right_y = y+1;

        // Recursive call for left and right childs
        helper(node->left, left_x, left_y);
        helper(node->right, right_x, right_y);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> out;
        vector<int> temp;

        // Start of dfs
        helper(root, 0, 0);

        // Populate the output vector
        for (auto p : posMap) {
            for (auto n : p.second) {
                //Populate each val of a specific x coord in a temp vector
                temp.push_back(n.second);
            }
            // Update out using the temp vector
            out.push_back(temp);
            temp.clear();
        }
        return out;
    }
};
