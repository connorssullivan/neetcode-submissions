class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int totalProduct {1};
        int zeroIndex {-1};
        int zeroCount {};

        std::vector<int> sol(nums.size());

        for (int i {}; i < nums.size(); i++)
        {
            totalProduct *= nums[i];
            if (nums[i] == 0)
            {
                zeroCount++;
                zeroIndex = i;
            }
        }

        if (zeroCount == 1)
        {
            totalProduct = 1;
            for (int i {}; i < nums.size(); i++)
            {
                if (i == zeroIndex)
                    continue;
                totalProduct *= nums[i];
            }
            sol[zeroIndex] = totalProduct;
        }

        else
        {
            for (int i {}; i < nums.size(); i++)
                if (nums[i] != 0)
                    sol[i] = totalProduct / nums[i];
        }

        return sol;
    }
};
