class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        int orange_count {};

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                {
                    orange_count++;
                }
            }
        }

        if (orange_count == 0)
            return 0;

        int most_time {-1};
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i {}; i < 4; ++i)
            {
                int new_r = r + dirs[i][0];
                int new_c = c + dirs[i][1];

                if (new_r >= 0 && new_r < ROWS && new_c >= 0 && new_c < COLS && grid[new_r][new_c] == 1)
                {
                    int new_tile = (grid[r][c] == 2) ? -1 : grid[r][c] - 1;
                    //std::cout << new_tile;
                    grid[new_r][new_c] = new_tile;
                    most_time = max(abs(grid[new_r][new_c]), most_time);
                    q.push({new_r, new_c});
                    orange_count--;
                }
            }
        }

        return (orange_count > 0 ) ? -1 : most_time;
    }
};
