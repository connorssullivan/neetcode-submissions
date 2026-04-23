class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> sol;

        for (auto& s : strs)
        {
            string sorted_str = s;
            sort(sorted_str.begin(), sorted_str.end());

            mp[sorted_str].push_back(s);
        }

        for (auto& [_, v] : mp)
        {
            sol.push_back(v);
        }

        return sol;

    }
};
