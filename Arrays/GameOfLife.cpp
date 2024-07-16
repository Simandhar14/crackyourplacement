class Solution
{
public:
    vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    void gameOfLife(vector<vector<int>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> copyBoard = board;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int count = 0;
                for (auto vec : dir)
                {
                    int x = i + vec[0];
                    int y = j + vec[1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols &&
                        copyBoard[x][y] == 1)
                        count++;
                }
                if (copyBoard[i][j] == 1)
                {
                    if (count < 2 || count > 3)
                        board[i][j] = 0;
                }
                else
                {
                    if (count == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};