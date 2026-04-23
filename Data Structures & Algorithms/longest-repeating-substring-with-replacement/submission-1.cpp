#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        if (s.length() == 0)
            return 0;

        std::unordered_map<char, int> counts;
        int left = 0;
        int right = 0;
        int res = 0;

        while (right < s.length()) {
            counts[s[right]]++;

            // Find the largest character count in current window
            int largest = 0;
            for (const auto& val : counts) {
                largest = std::max(largest, val.second);
            }

            int window_size = right - left + 1;

            // If we need to replace more than k chars, shrink the window
            if (window_size - largest > k) {
                counts[s[left]]--;
                left++;
            }

            res = std::max(res, right - left + 1);
            right++;
        }

        return res;
    }
};

