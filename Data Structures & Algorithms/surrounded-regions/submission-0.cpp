class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();

        auto dfs = [&] (auto&& self, int r, int c ) {
            if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != 'O')
                return;

            board[r][c] = 'T';
            self(self, r+1, c);
            self(self, r-1, c);
            self(self, r, c+1);
            self(self, r, c-1);
        };

        for (int i {}; i < COLS; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(dfs, 0, i);
            }

            if (board[ROWS-1][i] == 'O')
            {
                dfs(dfs, ROWS-1, i);
            }
        }

        for (int i {}; i < ROWS; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(dfs, i, 0);
            }

            if (board[i][COLS-1] == 'O')
            {
                dfs(dfs, i, COLS-1);
            }
        }

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};
