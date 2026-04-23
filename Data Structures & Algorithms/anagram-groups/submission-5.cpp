class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        
        std::unordered_map<std::string, std::vector<std::string>> mp;
        std::vector<std::vector<std::string>> sol;

        for (const auto& s : strs)
        {
            std::string key = s;
            std::sort(key.begin(), key.end());

            mp[key].push_back(s);
        }

        for (auto [_, group] : mp)
            sol.push_back(group);

        return sol;


    }
};
