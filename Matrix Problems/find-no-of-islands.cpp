
class Solution
{
public:
    // Function to find the number of islands.
    void solve(vector<vector<char>> &grid, int m, int n, int i, int j)
    {
        // Check for out-of-bounds indices and already visited cells
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || grid[i][j] == '$')
        {
            return;
        }
        grid[i][j] = '$';
        solve(grid, m, n, i - 1, j);
        solve(grid, m, n, i + 1, j);
        solve(grid, m, n, i, j - 1);
        solve(grid, m, n, i, j + 1);
        solve(grid, m, n, i - 1, j - 1);
        solve(grid, m, n, i - 1, j + 1);
        solve(grid, m, n, i + 1, j - 1);
        solve(grid, m, n, i + 1, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {

                if (grid[i][j] == '1')
                {
                    solve(grid, m, n, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};