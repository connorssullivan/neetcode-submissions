class Solution {

private: 
    unordered_map<int, bool> m_memo;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        

        auto dfs = [&] (auto&& self, int i) {
            if (m_memo.find(i) != m_memo.end())
                return m_memo[i];
            
            for (const auto& word : wordDict)
            {
                if (i + word.length() <= s.length() && 
                    s.substr(i, word.length()) == word)
                {
                    if (self(self, i + word.length()))
                    {
                        m_memo[i] = true;
                        return true;
                    }
                }
            }

            m_memo[i] = false;
            return false;
            
        };

        m_memo[s.length()] = true;
        return dfs(dfs, 0);
    }
};
