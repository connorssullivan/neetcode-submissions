class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::map<int, int> counts;

        std::vector<int> sol;

        for(int i : nums){

            counts[i]++;

            if(sol.size() < k && std::find(sol.begin(), sol.end(), i) == sol.end())
                sol.push_back(i);
            
            else {

                int min { sol[0] };
                int index { 1 };
                for (; index < sol.size(); index++)
                    if (counts[sol[index]] < counts[min])
                        min = sol[index];
                
                if (counts[i] > counts[min] && std::find(sol.begin(), sol.end(), i) == sol.end())
                    std::replace(sol.begin(), sol.end(), min, i);
                
            }

            std::cout << i << " Count: " << counts[i] << "\n";
            
        }
        
        for(auto num : sol)
            std::cout << num << "\n";
        return sol;
    }
};
