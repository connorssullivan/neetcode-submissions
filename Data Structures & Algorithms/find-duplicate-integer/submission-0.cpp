class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> map;

        for (int n : nums)
        {
            map[n] += 1;
            if (map[n] > 1)
                return n;
        }

        return -1;
        
    }
};
