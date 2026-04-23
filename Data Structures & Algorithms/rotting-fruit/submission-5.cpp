class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int min {0};
        int fresh {};

        int ROWS = grid.size();
        int COLS = grid[0].size();

        for (int i {}; i < ROWS; i++)
        {
            for (int j {}; j < COLS; j++)
            {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        if (fresh == 0)
            return 0;
        
        vector<vector<int>> dirs {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while (!q.empty() && fresh > 0)
        {
            int size = q.size();

            for (int i {}; i < size; i++)
            {
                auto& p = q.front();
                q.pop();

                for (auto& d : dirs)
                {
                    if (p.first + d[0] >= 0 && p.first + d[0] < ROWS &&
                        p.second + d[1] >= 0 && p.second + d[1] < COLS &&
                        grid[p.first + d[0]][p.second + d[1]] == 1)
                    {
                        grid[p.first + d[0]][p.second + d[1]] = 2;
                        q.push({p.first + d[0], p.second + d[1]});
                        fresh--;
                    }
                }
            }

            min++;
        }
        
        if (fresh==0)
            return min;
        return -1;
    }
};
