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
int dfs(TreeNode* root, int max_val){
    if (!root)
        return 0;
    
    
    int new_max = std::max(max_val, root->val);
    int val = (root->val >= max_val) ? 1 : 0;
    val += dfs(root->left, new_max);
    val += dfs(root->right, new_max);

    return val;
    
}
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
