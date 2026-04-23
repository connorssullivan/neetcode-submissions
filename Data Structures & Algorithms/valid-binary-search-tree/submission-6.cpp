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
    bool isValidBST(TreeNode* root) {
        auto dfs = [&] (auto&& self, TreeNode* root, int smallest, int largest) {
            if (!root) 
                return true;
            
            if (root->val >= largest)
                return false;
            if (root->val <= smallest)
                return false;
            return self(self, root->left, smallest, root->val) && self(self, root->right, root->val, largest);
            
        };
        return dfs(dfs, root, INT_MIN,INT_MAX);

    }
};
