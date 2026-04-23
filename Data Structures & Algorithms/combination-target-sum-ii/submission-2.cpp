class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        std::vector<int> nums;
        vector<vector<int>> sol;

        sort(candidates.begin(), candidates.end());

        auto dfs = [&] (auto&& self, int index, vector<int>& v, int total) {
            if (total == target)
            {
                sol.push_back(v);
                return;
            }

            if (index == candidates.size() || total > target)
                return;
        
            v.push_back(candidates[index]);

            self(self, index + 1, v, total + candidates[index]);
            v.pop_back();

            while (index + 1 < candidates.size() && candidates[index] == candidates[index+1])
                index++;
            self(self, index+1, v, total);
        };

        dfs(dfs, 0, nums, 0);
        return sol;
    }
};
