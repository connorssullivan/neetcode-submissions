class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.length();
        int res {};

        for (int i {}; i < n; ++i)
        {
            int left {i};
            int right {i};

            while (left >= 0 && right < n && s[left] == s[right])
            {
                res++;
                left--;
                right++;
            }

            left = i;
            right = i+1;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                res++;
                left--;
                right++;
            }
        }

        return res;
    }
};
