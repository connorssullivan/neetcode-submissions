class Solution {
public:
    bool isPalindrome(string s) {
        int left {0}; 
        int right = s.length();

        while (left <= right)
        {

            while (!std::isalnum((unsigned char)s[left]))
                left++;
            while (!std::isalnum((unsigned char)s[right]))
                right--;

            if (left > right)
                return true;
            else if (tolower(s[left]) != tolower(s[right]))
                return false;
            else 
            {
                left++;
                right--;
            }
        }

        return true;
        
    }
};
