#include <vector>
#include <iostream>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

        std::vector<std::vector<int>> sol {};
        std::set<std::vector<int>> unique_set {};


        int n { static_cast<int> (nums.size())};


        for (int i=0; i < n -2; i++)
        {
           
            for (int j=i+1; j< n -1; j++)
            {
                
                for (int k=j+1; k < n ; k++)
                {
                    
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        std::vector<int> temp {nums[i], nums[j], nums[k]};
                        std::sort(temp.begin(), temp.end());
                        unique_set.insert(temp);
                    }
                }
            }
        }

        sol.assign(unique_set.begin(), unique_set.end());
        return sol;
    }

    void printSol(const std::vector<std::vector<int>> arr) {
        std::cout << "[";
        for (auto v : arr)
        {
            std::cout << "[";
            for (auto n : v)
            {
                std::cout << n << ",";
            }
            std::cout << "]";
        }
        std::cout << "]";
    }
};

