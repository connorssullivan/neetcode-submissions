class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> connections(n);
        vector<bool> visted(n, false);

        for (const auto& edge : edges)
        {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }
        int islands {};
        auto dfs = [&] (auto&& self, int node) ->void{
            visted[node] = true;

            for (const int edge : connections[node])
            {
                if (!visted[edge])
                {
                    self(self, edge);
                }
            }
        };

        for (int i {}; i < n; i++)
        {
            if (!visted[i])
            {
                dfs(dfs, i);
                islands++;
            }
        }

        return islands;
    }
};
