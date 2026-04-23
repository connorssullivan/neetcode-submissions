class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> sol;
        vector<int> curr;

        auto dfs = [&] (auto&& self, int index, int total) {

            if (target == total)
            {
                sol.push_back(curr);
                return;
            }

            if (total > target || index >= nums.size())
            {
                return;
            }
            
            curr.push_back(nums[index]);
            self(self, index, total+nums[index]);
            curr.pop_back();
            self(self, index+1, total);
        };

        dfs(dfs,0,0);

        return sol;
    }
};
