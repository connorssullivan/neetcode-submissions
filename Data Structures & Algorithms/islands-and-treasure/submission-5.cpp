class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        queue<pair<int, int>> frontier;

        std::vector<std::vector<int>> seen(ROWS, vector<int>(COLS, 0));

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (grid[i][j] == 0)
                {
                    frontier.push({i, j});
                    seen[i][j] = 1;
                }
            }
        }


        vector<vector<int>> dirs = { {1,0}, {-1, 0}, {0, 1}, {0, -1} };
        int land {2147483647};
        while (!frontier.empty())
        {
            int curr_size = frontier.size();

            for (int i {}; i < curr_size; i++)
            {
                auto curr = frontier.front();
                frontier.pop();

                for (auto& d : dirs)
                {
                    if (curr.first + d[0] >= 0 && curr.first + d[0] < ROWS &&
                        curr.second + d[1] >= 0 && curr.second + d[1] < COLS &&
                        grid[curr.first+d[0]][curr.second+d[1]] == land &&
                        seen[curr.first+d[0]][curr.second+d[1]] == 0)
                        {
                            grid[curr.first+d[0]][curr.second+d[1]] = grid[curr.first][curr.second]+1;
                            frontier.push({ curr.first+d[0], curr.second+d[1] });
                            seen[curr.first+d[0]][curr.second+d[1]] = 1;
                        }
                }
            }
        }
    }
};
