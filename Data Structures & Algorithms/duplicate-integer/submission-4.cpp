class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        std::map<int, int> counts;

        for(auto i : nums){
            counts[i]++;
            if(counts[i] > 1)
                return true;
        }

        return false;
    }
};