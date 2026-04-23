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

#include <vector>
#include <iterator> 
#include <algorithm>


class Solution {
private:
    int pre_index = 0;
    int inIndex = 0;
    TreeNode* dfs(std::vector<int>& preorder, std::vector<int>& inorder, int limit) {
        if (pre_index >= preorder.size())
            return nullptr;
        
        if (inorder[inIndex] == limit)
        {
            inIndex++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_index++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, limit);
        return root;
    }

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};
