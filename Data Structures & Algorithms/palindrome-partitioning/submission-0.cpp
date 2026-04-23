class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> curr;

        auto isPalidrone = [s] (int left, int right) -> bool {
            while (left < right)
            {
                if (s[left] != s[right])
                    return false;
                left++;
                right--;
            }
            return true;
        };

        auto dfs = [&] (auto&& self, int index) {
            if (index >= s.size())
            {
                res.push_back(curr);
                return;
            }

            for (int j {index}; j < s.size(); j++)
            {
                if (isPalidrone(index, j))
                {
                    curr.push_back(s.substr(index, j-index+1));
                    self(self, j+1);

                    curr.pop_back();
                }
            }
        };

        dfs(dfs, 0);

        return res;
    }
};
