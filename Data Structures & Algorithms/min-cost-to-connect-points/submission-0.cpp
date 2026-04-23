class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> adj;
        const int N = points.size();

        for (int i {}; i < N; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j {i+1}; j < N; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                adj[i].emplace_back(dist, j);
                adj[j].emplace_back(dist, i);
            }
        }


        int res {};
        unordered_set<int> visted;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

        minH.push({0, 0});

        while (!minH.empty() && visted.size() < N)
        {
            auto curr = minH.top(); minH.pop();

            int dist = curr.first;
            int i = curr.second;

            if (visted.count(i))
                continue;
            
            res += dist;
            visted.insert(i);

            for (auto& [cost, nei] : adj[i])
                if (!visted.count(nei))
                    minH.push({cost, nei});
        }

        return res;
    }
};
