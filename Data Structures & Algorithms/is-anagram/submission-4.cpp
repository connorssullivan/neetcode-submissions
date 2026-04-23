class Solution {
public:

    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        std::map<char,int> s_word;
        std::map<char,int> t_word;

        for(int i=0; i<s.size();i++){
            s_word[s[i]]++;
            t_word[t[i]]++;
        }

        if(s_word == t_word)
            return true;
        return false;
    }
};
