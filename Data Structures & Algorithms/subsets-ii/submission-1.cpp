class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> curr;
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());

        auto dfs = [&] (auto&& self, int index) {

            if (index == nums.size())
            {
                sol.push_back(curr);
                return;
            }
            
            curr.push_back(nums[index]);
            self(self, index+1);
            curr.pop_back();

            int shifter = index+1;
            while (shifter < nums.size() && nums[shifter] == nums[index])
                shifter++;

            self(self, shifter);
        };

        dfs(dfs, 0);

        return sol;
    }

    // 112

};
