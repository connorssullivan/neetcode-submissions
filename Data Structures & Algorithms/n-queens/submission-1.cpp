class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols (n, false);
        vector<bool> neg_diag (n*2, false);
        vector<bool> pos_diag (n*2, false);
        vector<vector<string>> res;
        vector<string> board;
        board.resize(n, string(n, '.'));

        auto backTrack = [&] (auto&& self, int r) {
            if (r == board.size())
            {
                res.push_back(board);
                return;
            }

            for (int c {}; c < board.size(); c++)
            {
                if (cols[c] || neg_diag[r-c+n] || pos_diag[r+c])
                    continue;

                cols[c] = true;
                neg_diag[r-c+n] = true;
                pos_diag[r+c] = true;
                board[r][c] = 'Q';

                self(self, r+1);

                cols[c] = false;
                neg_diag[r-c+n] = false;
                pos_diag[r+c] = false;
                board[r][c] = '.';

            }
        };

        backTrack(backTrack, 0);
        return res;

        
    }
};
