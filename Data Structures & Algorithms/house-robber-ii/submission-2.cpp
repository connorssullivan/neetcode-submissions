class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size()==0)
            return 0;
        unordered_map<int, int> mp1, mp2;


        auto getMaxRob = [&] (auto&& self, int i, int end, unordered_map<int, int>& memo) {

            if (i >= end)
            {
                return 0;
            }

            if (memo.count(i))
            {
                return memo[i];
            }
            
            else
            {
                int val = max(nums[i] + self(self, i+2, end, memo), self(self, i+1, end, memo));
                memo[i] = val;
                return val;
            }

        };

        return max(getMaxRob(getMaxRob, 0, nums.size()-1, mp1), getMaxRob(getMaxRob, 1, nums.size(), mp2));
    }
};
