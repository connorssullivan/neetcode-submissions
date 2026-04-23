class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> par(n + 1);
        vector<int> rank(n + 1, 1);


        for (int i {}; i <= n; i++)
            par[i] = i;

        auto find = [&] (int node) {
            int p = par[node];

            while (p != par[p])
            {
                par[p] = par[par[p]];
                p = par[p];
            }

            return p;
        };

        auto Union = [&] (int node1, int node2) {
            int p1 = find(node1);
            int p2 = find(node2);

            if (p1 == p2)
                return false;
            if (rank[p1] > rank[p2])
            {
                par[p2] = p1;
                rank[p1] += rank[p2];
            }

            else 
            {
                par[p1] = p2;
                rank[p2] += rank[p1];
            }

            return true;
        };

        for (const auto& edge : edges) 
        {
            if(!Union(edge[0], edge[1]))
                return vector<int> {edge[0], edge[1]};
        }
        return {};
    }
};
