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
    int goodNodes(TreeNode* root) {
        
        int good_nodes {};

        auto dfs = [&] (auto&& self, TreeNode* curr, int max) {
            if (!curr)
                return;
            
            if (curr->val >= max)
            {
                max = curr->val;
                good_nodes++;
            }

            self(self, curr->left, max);
            self(self, curr->right, max);

        };

        if (root)
            dfs(dfs, root, root->val);
            
        return good_nodes;
    }
};
