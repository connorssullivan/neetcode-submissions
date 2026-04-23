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
private:

public:
    int diameterOfBinaryTree(TreeNode* root) {
       int diam = 0;

        auto dfs = [&](auto&& self, TreeNode* curr) -> int {
            if (!curr)
                return 0;

            int left = self(self, curr->left);
            int right = self(self, curr->right);

            diam = max(diam, left+right);

            return max(left,right) + 1;
        };

        dfs(dfs, root);

        return diam;
       
    }
};
