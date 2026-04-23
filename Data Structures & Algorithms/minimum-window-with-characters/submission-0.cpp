#include <string>
#include <unordered_map>


class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (t.length() > s.length())
            return "";
        
        std::string res {""};

        std::unordered_map<char, int> t_counts;
        std::unordered_map<char, int> window;

        for (auto c : t)
        {
            t_counts[c]++;
        }


        int left {0};
        int right {0};
        int have {0};
        int need {t_counts.size()};

        while (right < s.length())
        {
            window[s[right]]++;

            if (t_counts.count(s[right]) && window[s[right]] == t_counts[s[right]])
            {
                have++;

                while (have == need)
                {
                    std::string temp = s.substr(left, right - left + 1);
                    if (res.length() == 0 || res.length() > temp.length())
                        res = temp;



                    if (t_counts.count(s[left]) && t_counts[s[left]] == window[s[left]])
                        have--;
                    window[s[left]]--;

                    left++;
                }
            }

            right++;
        }

        return res;
    }
        
};