class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;

        auto backTrack = [&] (auto&& self, int open, int closed, string& str) {
            if (open == n && closed == open)
            {
                res.push_back(str);
                return;
            }

            if (open < n)
            {
                str += "(";
                self(self, open+1, closed, str);
                str.pop_back();
            }

            if (closed < open)
            {
                str += ")";
                self(self, open, closed+1, str);
                str.pop_back();
            }
        };
        string s;
        backTrack(backTrack, 0, 0, s);
        return res;
    }
};
