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
#include <map>

class Solution {
private:
    int makeMap(TreeNode* root, std::map<int, std::vector<int>>& mp, int level=0){
        if (!root)
            return level;
        mp[level].push_back(root->val);

        int left = makeMap(root->left, mp, level + 1);
        int right = makeMap(root->right, mp, level + 1);
        
        return std::max(left, right);
    }

public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> sol;
        std::map<int, std::vector<int>> mp;

        int levels = makeMap(root, mp);

        for (int i {}; i < levels; i++)
            sol.push_back(mp[i]);

        return sol;
    }
};
