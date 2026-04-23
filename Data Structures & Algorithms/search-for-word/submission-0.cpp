class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int ROWS = board.size();
        const int COLS = board[0].size();

        auto dfs = [&] (auto&& self, int r, int c, int i) {
            if (i == word.size())
                return true;
            
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != word[i] || board[r][c] == '#') 
            {
                return false;
            }

            board[r][c] = '#';
            bool res = (self(self, r+1, c, i+1)
                        || self(self, r-1, c, i+1)
                        || self(self, r, c+1, i+1) 
                        || self(self, r, c-1, i+1)
                        );

            board[r][c] = word[i];

            return res;

        };

        for (int r {}; r < ROWS; r++)
        {
            for (int c {}; c < COLS; c++)
            {
                if (dfs(dfs, r, c, 0))
                    return true;
            }
        }
        return false;
    }
};
