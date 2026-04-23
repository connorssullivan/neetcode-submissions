#include <iostream>
#include <deque>
#include <unordered_set>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty())
            return 0;

        std::deque<char> dq;
        std::unordered_set<char> seen;
        int max_string {1};
        int streak {0};

        for (char c : s)
        {
            int sub_streak {0};
            if (seen.count(c))
            {
                while (!dq.empty())
                {
                    char front = dq.front();
                    seen.erase(front);
                    dq.pop_front();
                    sub_streak++;
                    if (front == c)
                        break;
                }
            }
            seen.insert(c);
            dq.push_back(c);
            streak++;
            streak -= sub_streak;

            max_string = std::max(streak, max_string);

        }

        return max_string;
    }
};
