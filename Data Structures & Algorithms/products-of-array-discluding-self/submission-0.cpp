class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        
        std::vector<int> sol;

        for (int i=0; i < nums.size(); i++)
        {
            int tempNum {1};
            for (int j=0; j < nums.size(); j++)
            {
                if (j != i) {
                    tempNum *= nums[j];
                }
            }
            sol.push_back(tempNum);
        }
        return sol;
    }
};
