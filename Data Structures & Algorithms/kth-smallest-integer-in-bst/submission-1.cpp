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

class eval 
{
    bool operator()(const int num1, const int num2)
    {
        return num1 < num2;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //vector<int> vec;
        int index {0};
        int smallest {-1};

        auto dfs = [&] (auto&& self, TreeNode* curr) {
            if (!curr)
                return;

            self(self, curr->left);
            index++;
            if (index == k)
            {
                smallest = curr->val;
                return;
            }
            self(self, curr->right);
        };

         dfs(dfs, root);
         return smallest;

        
    }
};
