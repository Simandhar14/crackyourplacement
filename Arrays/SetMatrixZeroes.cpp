class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> index;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = matrix.size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                    index.push_back({i, j});
            }
        }
        for (auto vec : index)
        {
            int i = vec.first;
            int j = vec.second;
            for (int idx = 0; idx < cols; idx++)
            {
                matrix[i][idx] = 0;
            }
            for (int idx = 0; idx < rows; idx++)
            {
                matrix[idx][j] = 0;
            }
        }
    }
};