class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int N = nums.size();
        vector<vector<int>> sol;
        vector<int> v;

        auto dfs = [&] (auto&& self, int index, int total) {
            if (total == target)
            {
                sol.push_back(v);
                return;
            }

            if (index == N || total > target)
                return;

            v.push_back(nums[index]);
            self(self, index, total + nums[index]);
            v.pop_back();
            self(self, index+1, total);
        };

        dfs(dfs, 0, 0);
        return sol;
    }
};
