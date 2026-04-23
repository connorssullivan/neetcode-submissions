class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int min_cost {};

        auto dfs = [&] (auto&& self, int i) {
            if (i >= cost.size())
                return 0;
            
            return cost[i] + std::min(self(self, i+1), self(self, i+2));
        };

        return std::min(dfs(dfs,0), dfs(dfs, 1));
    }
};





