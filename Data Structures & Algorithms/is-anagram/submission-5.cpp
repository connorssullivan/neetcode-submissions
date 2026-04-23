class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length())
            return false;

        std::unordered_map<char, int> mp;
        int count = s.length();

        for (char c : s)
            mp[c]++;
        
        for (const char c : t)
        {
            if (!mp.count(c) || mp[c] == 0)
                return false;
            
            mp[c]--;
        }

        return true;
            
    }
};
