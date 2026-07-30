class Solution {
public:

    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0)
        {
            return 0;
        }

        grid[row][col] = 0;

        int area = 1;

        area += dfs(grid, row + 1, col);
        area += dfs(grid, row - 1, col);
        area += dfs(grid, row, col + 1);
        area += dfs(grid, row, col - 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};