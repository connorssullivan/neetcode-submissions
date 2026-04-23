class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total {1};
        int zero_count {0};
        int zero_index;
        for (int i {}; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zero_index = i;
                zero_count++;
                continue;
            }
            total *= nums[i];
        }

        vector<int> sol(nums.size(), 0);
        if (zero_count == 1)
        {
            sol[zero_index] = total;
        }   

        else if (zero_count > 1)
            return sol;
        
        else 
        {
            for (int i {}; i < nums.size(); i++)
                sol[i] = total / nums[i];
        }

        return sol;
    }
};
