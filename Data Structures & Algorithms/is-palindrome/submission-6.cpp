class Solution {
public:
    bool isPalindrome(std::string s) {
        int leftIndex {0};
        int rightIndex { static_cast<int>(s.size() - 1) };

        while (leftIndex < rightIndex)
        {
            char leftChar = std::tolower(s[leftIndex]);
            char rightChar = std::tolower(s[rightIndex]);

            std::cout << "LeftChar: " << leftChar << " RightChar: "  << rightChar <<"\n";

            if (leftChar > 'z' || leftChar < 'a')
            {
                if (leftChar < '0' || leftChar > '9')
                {
                    leftIndex++;
                    continue;
                }
            }

            if (rightChar > 'z' || rightChar < 'a')
            {
                if (rightChar < '0' || rightChar > '9')
                {
                    rightIndex--;
                    continue;
                }
                
            }

            if (leftChar != rightChar)
                return false;
            
            leftIndex++;
            rightIndex--;
        }

        return true;
        
    }
};

