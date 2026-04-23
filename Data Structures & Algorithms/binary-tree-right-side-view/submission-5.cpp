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
    std::vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        std::queue<TreeNode*> q;
        std::vector<int> sol;


        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            for (int i {}; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if (i == size -1)
                {
                    sol.push_back(temp->val);
                }

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        return sol;
    }
};
