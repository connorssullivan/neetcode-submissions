class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int N = nums.size();

        vector<vector<int>> sol;


        auto dfs = [&] (auto&& self, int index, vector<int>& arr) {
            if (index == N)
            {
                sol.push_back(arr);
                return;
            }

            self(self, index+1, arr);
            arr.push_back(nums[index]);
            self(self, index+1, arr);
            arr.pop_back();
        };


        vector<int> v;
        dfs(dfs, 0, v);

        return sol;
    }
};
