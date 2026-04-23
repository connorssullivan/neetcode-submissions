class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int ROW = board.size();
        const int COL = board[0].size();

        std::unordered_map<int, std::unordered_set<char>> rows;
        std::unordered_map<int, std::unordered_set<char>> cols;
        std::unordered_map<std::string, std::unordered_set<char>> squares;


        for (int i {}; i < ROW; i++)
        {
            for (int j {}; j < COL; j++)
            {
                if (board[i][j] == '.')
                    continue;
                
                int squareR = i/3;
                int squareC = j/3;

                std::string quadrant;
                quadrant += to_string(squareR);
                quadrant += to_string(squareC);

                if (rows[i].find(board[i][j]) != rows[i].end() || cols[j].find(board[i][j]) != cols[j].end() || squares[quadrant].find(board[i][j]) != squares[quadrant].end())
                    return false;
                
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                squares[quadrant].insert(board[i][j]);
                
            }
        }

        return true;
    }
};
