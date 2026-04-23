class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> curr;
        int n = nums.size();

        auto dfs = [&] (auto&& self, int index) {
            if (index == n)
            {
                sol.push_back(curr);
                return;
            }

            curr.push_back(nums[index]);
            self(self, index+1);

            curr.pop_back();
            self(self, index+1);
        };

        dfs(dfs,0);
        return sol;
    }
};
