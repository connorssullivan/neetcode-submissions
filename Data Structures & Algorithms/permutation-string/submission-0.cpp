#include <string>
#include <unordered_map>



class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {

        std::unordered_map<char, int> str;
        for (char c : s1)
        {
            str[c]++;
        }

        std::unordered_map<char, int> subStr;
        int left {0};
        int right {0};

        while (right < s2.size())
        {
            subStr[s2[right]]++;
            if (right - left + 1 == s1.size())
            {
                if (subStr != str)
                {
                    subStr[s2[left]]--;
                    if (subStr[s2[left]] == 0)
                        subStr.erase(s2[left]);
                    left++;
                }
                else return true;
            }


            right++;
        }

        return false;

    }
};


