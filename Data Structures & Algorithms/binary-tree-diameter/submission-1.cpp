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
    int diameterOfBinaryTree(TreeNode* root) {

        int max_diameter {};
        
        auto dfs = [&] (auto&& self, TreeNode* curr) {
            if (!curr)
                return 0;
            
            
            int left = self(self, curr->left);
            
            int right = self(self, curr->right);

            int total = left+right;

            max_diameter = max(max_diameter, left+right);
            return 1 + max(left, right);
        };

        dfs(dfs, root);
        return max_diameter;
    }
};
