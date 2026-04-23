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

        if (!node)
            return nullptr;

        Node* head = new Node(node->val);
        Node* curr = node;

        unordered_map<Node*, Node*> mp;
        mp[node] = head;

        unordered_set<Node*> seen;
        seen.insert(node);

        queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            Node* n = q.front();
            q.pop();

            for (int i {}; i < n->neighbors.size(); i++)
            {
                if (seen.find(n->neighbors[i]) == seen.end())
                {
                    Node* newNode = new Node(n->neighbors[i]->val);
                    seen.insert(n->neighbors[i]);
                    q.push(n->neighbors[i]);

                    mp[n->neighbors[i]] = newNode;
                }

                mp[n]->neighbors.push_back(mp[n->neighbors[i]]);
            }
        }

        return head;
    }
};
