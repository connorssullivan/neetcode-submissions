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
    void dfs(TreeNode* root, int depth,std::vector<int>& vec)
    {
        if (!root)
            return;
        
        if (vec.size() == depth)
            vec.push_back(root->val);
        
        dfs(root->right, depth + 1,vec);
        dfs(root->left, depth + 1,vec);
    }
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> vec;
        dfs(root, 0,vec);

        return vec;
    }
};
