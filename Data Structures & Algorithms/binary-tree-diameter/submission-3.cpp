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
    int dfs(TreeNode* root, int& max_diam) 
    {
        if (!root)
            return 0;

        int left = dfs(root->left, max_diam);
        int right = dfs(root->right, max_diam);

        max_diam = max(max_diam, left + right);
        return 1 + max(left, right);
    }   

public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diam = 0;
        dfs(root, diam);

        return diam;
    }
};
