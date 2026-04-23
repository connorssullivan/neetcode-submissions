class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();


        queue<pair<int, int>> q;

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        } 

        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i {}; i < dirs.size(); i++)
            {
                int r2 = r + dirs[i][0];
                int c2 = c + dirs[i][1];

                if (r2 < 0 || c2 < 0 || r2 >= ROWS || c2 >= COLS || grid[r2][c2] != INT_MAX)
                    continue;
                
                grid[r2][c2] = grid[r][c] + 1;
                q.push({r2, c2});
            }
        }
    }
};
