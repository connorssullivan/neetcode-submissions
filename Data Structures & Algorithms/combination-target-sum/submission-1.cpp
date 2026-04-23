class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int N = nums.size();
        vector<vector<int>> sol;

        auto dfs = [&] (auto&& self,int index, int sum, vector<int>& v) {
            
            if (index >= N || sum > target)
                return;

            if (sum == target)
            {
                sol.push_back(v);
                return;
            }
            
            v.push_back(nums[index]);
            self(self, index, sum + nums[index], v);
            v.pop_back();
            self(self, index+1, sum, v);
        };

        vector<int> arr;
        dfs(dfs, 0, 0,arr);

        return sol;
    }
};
