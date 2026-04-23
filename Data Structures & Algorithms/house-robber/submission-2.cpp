class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);

        auto dfs = [&] (auto&& self, int i) {
            if (i >= nums.size())
                return 0;
            
            if (memo[i] != -1)
                return memo[i];
            
            int val = max(nums[i] + self(self, i+2), self(self,i+1));
            memo[i] = val;
            return val;

        };

        return dfs(dfs, 0);
    }
};
