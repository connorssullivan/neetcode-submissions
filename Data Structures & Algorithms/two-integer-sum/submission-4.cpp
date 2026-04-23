class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i {}; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }

        for (int i {}; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (mp.count(diff) && mp[diff] != i)
            {
                return {i, mp[diff]};
            }
        }
        

        return {};
    }
};
