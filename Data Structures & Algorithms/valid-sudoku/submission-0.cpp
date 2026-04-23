#include <iostream>
#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::vector<char>> rows;
        std::vector<std::vector<char>> cols;
        std::vector<std::vector<char>> tiles;

        int square {1};
        for (int i=0; i < board.size(); i++)
        {
            std::vector<char> row;

            for (int j=0; j < board.size(); j++)
            {
                // If the column doesnt exist create a new column
                if (cols.size() < j+1)
                {
                    std::vector<char> col;
                    cols.push_back(col);
                }
                
                
                if (std::find(cols[j].begin(), cols[j].end(), board[i][j]) != cols[j].end() && board[i][j] != '.')
                {
                    cols[j].push_back(board[i][j]);
                    std::cout << "Columns Returning false\n";
                    for (auto temp1 : cols)
                    {
                        std::cout << "[\n";
                        for (auto temp2 : temp1)
                            std::cout << temp2 << ",";
                    }
                    std::cout << "]\n";
                    return false;
                }

                // This is making our columns
                cols[j].push_back(board[i][j]);

                if (std::find(row.begin(), row.end(), board[i][j]) != row.end() && board[i][j] != '.')
                {
                    row.push_back(board[i][j]);
                    rows.push_back(row);
                    std::cout << "Rows Returning false\n";
                    for (auto temp1 : rows)
                    {
                        std::cout << "[\n";
                        for (auto temp2 : temp1)
                            std::cout << temp2 << ",";
                    }
                    std::cout << "]\n";
                    return false;
                }
                // This is making our rows
                row.push_back(board[i][j]);

                // Get the square coordiante
                int box_cord { ((i/3) * 3) + (j/3) };

                if (tiles.size() < box_cord+1)
                {
                    std::vector<char> box;
                    tiles.push_back(box);
                }


                if (std::find(tiles[box_cord].begin(), tiles[box_cord].end(), board[i][j]) != tiles[box_cord].end() && board[i][j] != '.')
                {
                    
                    return false;
                }
                tiles[box_cord].push_back(board[i][j]);

            }

            rows.push_back(row);
        }

        return true;
    }
};
