class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> sol;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        auto dfs = [&] (auto&& self, int index, int total) {

            if (total == target)
            {
                sol.push_back(curr);
                return;
            }

            if (index >= candidates.size() || total > target)
            {
                return;
            }

    
            curr.push_back(candidates[index]);
            self(self, index+1, total+candidates[index]);
            curr.pop_back();

            
            while (index < candidates.size()-1 && candidates[index] == candidates[index+1])
                index++;
            
            self(self, index+1, total);

        };

        dfs(dfs, 0, 0);
        return sol;
    }
};
