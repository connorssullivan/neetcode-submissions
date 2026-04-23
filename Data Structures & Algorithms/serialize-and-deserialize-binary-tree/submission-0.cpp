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

class Codec {
private:
    void dfsS(TreeNode* root, std::string& str){
        if (!root)
        {
            str += "N,";
            return;                        
        }

        str += std::to_string(root->val) + ",";
        dfsS(root->left, str);
        dfsS(root->right, str);
    }

    TreeNode* dfsD(std::string str, size_t& start_index) {
        int next_comma = str.find(',', start_index);
        if (next_comma ==  std::string::npos)
        {
            return nullptr;
        }

        std::string next_number = str.substr(start_index, next_comma - start_index);
        start_index = next_comma+1;
        if (next_number == "N")
        {
            return nullptr;
        }

        int num = stoi(next_number);
        TreeNode* newNode = new TreeNode(num);

        newNode->left = dfsD(str, start_index);
        newNode->right = dfsD(str, start_index);

        return newNode;

    }
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string str {};
        dfsS(root, str);

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        size_t index {0};
        TreeNode* root = dfsD(data, index);

        return root;
    }
};
