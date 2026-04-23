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
    int goodNodes(TreeNode* root) {
        int good_nodes {};

        auto dfs = [&] (auto&& self, TreeNode* root, int largest_value) {
            if (!root)
                return;
            if (largest_value <= root->val)
                good_nodes++;

            largest_value = std::max(largest_value, root->val);

            self(self, root->left, largest_value);
            self(self, root->right, largest_value);
            
        };

        dfs(dfs, root, root->val);

        return good_nodes;
    }
};
