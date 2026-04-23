class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N = cost.size();
        vector<int> memo(cost.size(), INT_MAX);

        auto dfs = [&] (auto&& self, int index) {

            if (index >= N)
                return 0;
            
            if (index > N)
                return INT_MAX;
            
            if (memo[index] != INT_MAX)
                return memo[index];

            memo[index] = cost[index] + min(self(self, index+1), self(self, index+2));

            return memo[index];
        };

        dfs(dfs, 0);
        return min(memo[0], memo[1]);


    }
};
