class Solution
{
public:
    bool row[10][10], col[10][10], vis[10][10], mark = false;
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int x = 0;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i<board.size(); i++)
        {
            for(int j = 0; j<board[i].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    x = board[i][j] - '0';
                    if(row[i][x] == true)
                        return false;
                    if(col[j][x] == true)
                        return false;
                    if(vis[i/3*3+j/3][x] == true)
                        return false;
                    row[i][x] = col[j][x] = vis[i/3*3+j/3][x] = true;
                }
            }
        }
        return true;
    }
};
