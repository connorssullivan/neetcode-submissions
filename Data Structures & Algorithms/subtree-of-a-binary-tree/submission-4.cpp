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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        auto dfs = [] (auto& self, TreeNode* r, TreeNode* s) {
            if (!s && !r)
            {
                return true;
            }
            if (!r || !s || r->val != s->val)
                return false;
            
            return self(self, r->left, s->left) && self(self, r->right, s->right);
            
        };
        if (!root)
            return false;
        if(dfs(dfs, root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
