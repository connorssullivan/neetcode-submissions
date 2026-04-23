class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res {nums[0]};
        int curr_max {1};
        int curr_min {1};

        for (const int num : nums)
        {
            int temp_max {curr_max * num};
            int temp_min {curr_min * num};

            curr_max = max(max(temp_max, temp_min), num);
            curr_min = min(min(temp_max, temp_min), num);

            res = max(curr_max, res);
        } 

        return res;
        
    }
};
