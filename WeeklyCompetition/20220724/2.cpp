class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        vector<vector<int>> candidate;
        for (int i = 0; i < grid.size(); i++)
        {
            int row_start = grid[i][0];
            for (int j = 0; j < grid[0].size(); j++)
            {
                int col_start = grid[0][j];
                if (row_start == col_start)
                    candidate.push_back({i, j});
            }
        }
        int wrong = 0;
        for (auto &c : candidate)
        {
            int row = c[0], col = c[1];
            for (int i = 1; i < grid.size(); i++)
            {
                if (grid[row][i] != grid[i][col])
                {
                    wrong++;
                    break;
                }
            }
        }
        return candidate.size() - wrong;
    }
};