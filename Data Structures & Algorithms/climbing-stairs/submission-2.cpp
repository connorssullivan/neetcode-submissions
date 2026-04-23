class Solution {
public:
    int climbStairs(int n) {
        int total {};

        vector<int> memo(n, -1);

        auto dfs = [&] (auto&& self, int sum) {
            if (sum == n)
                return 1;
            if (sum > n)
                return 0;

            if (memo[sum] != -1)
                return memo[sum];
            
            memo[sum] = self(self, sum+1) + self(self, sum+2);
            return memo[sum]; 
        };

        total = dfs(dfs, 0);

        return total;
    }
};
