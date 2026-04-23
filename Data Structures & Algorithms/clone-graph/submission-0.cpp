/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;

        auto dfs = [&] (auto&& self,Node* root) -> Node* {
            if (!root)
                return nullptr;
            
            if (mp.count(root))
                return mp[root];
            
            Node* newNode = new Node(root->val);
            mp[root] = newNode;
            for (auto* n : root->neighbors)
                newNode->neighbors.push_back(self(self,n));
            return newNode;
        }; 

        return dfs(dfs, node);
    }
};
