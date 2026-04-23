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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;

        queue<TreeNode*> nodes;
        
        nodes.push(root);

        while (!nodes.empty())
        {
            int len = nodes.size();
            
            TreeNode* rightMost = nullptr;
            for (int i {}; i < len; i++)
            {
                TreeNode* temp = nodes.front();
                nodes.pop();

                if (temp)
                {
                    nodes.push(temp->left);
                    nodes.push(temp->right);
                    rightMost = temp;
                }

            }
            if (rightMost)
                    sol.push_back(rightMost->val);
        }

        return sol;
        
    }
};
