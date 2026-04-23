#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        
        std::vector<std::vector<int>> sol;
        std::vector<int> curr; 

        std::sort(candidates.begin(), candidates.end());

        auto dfs = [&](auto&& self,int index, int total){

            if (total == target)
            {   
                sol.push_back(curr);
                return;
            }

            if (total > target || index >= candidates.size())
            {
                return;
            }

            curr.push_back(candidates[index]);
            self(self, index+1, total + candidates[index]);
            curr.pop_back();

            while (index < candidates.size() && candidates[index] == candidates[index+1])
                index++;
            
            if (index < candidates.size())
                self(self, index+1,total);
        };


        dfs(dfs, 0, 0);

        return sol;
    }
};