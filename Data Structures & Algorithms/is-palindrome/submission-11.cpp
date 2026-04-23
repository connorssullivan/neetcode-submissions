
class Solution {
public:
    bool isPalindrome(std::string s) {
        int left {0};
        int right = s.length() - 1;
        
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {return std::tolower(c);});

        while (left <= right)
        {
            while (left < right && !std::isalnum(s[left]))
                left++;
            while (right > left && !std::isalnum(s[right]))
                right--;

            if (left > right)
                break;
            
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};
