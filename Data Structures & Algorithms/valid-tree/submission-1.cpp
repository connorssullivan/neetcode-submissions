class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> visted;
        vector<vector<int>> adj(n);

        for (const auto& e : edges)
        {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }

        auto dfs = [&] (auto&& self, int curr, int par) {
            if (visted.count(curr))
                return false;
            
            visted.insert(curr);
            for (const int child : adj[curr])
            {
                if (child == par)
                    continue;
                if (!self(self, child, curr))
                    return false;
            }

            return true;
        };

        if (!dfs(dfs, 0, -1))
            return false;

        return visted.size() == n;
    }
};
