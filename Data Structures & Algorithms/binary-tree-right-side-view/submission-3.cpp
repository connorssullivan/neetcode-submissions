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
        std::vector<int> vec;
        std::deque<TreeNode*> dq;

        if (!root)
            return vec;

        dq.push_back(root);

        while(!dq.empty())
        {
            int size = dq.size();
            vec.push_back(dq.back()->val);

            for (int i {}; i < size; i++)
            {
                if (dq.front()->left)
                    dq.push_back(dq.front()->left);
                if (dq.front()->right)
                    dq.push_back(dq.front()->right);
                
                dq.pop_front();
            }
        }

        return vec;
    }
};
