//采用dfs搜索对每一位进行搜索，式一种比较暴力的方法
class Solution
{
public:
    bool row[10][10], col[10][10], vis[10][10], mark = false;
    int x, y;
    vector<vector<char> > tmp;
    void solveSudoku(vector<vector<char>>& board)
    {

        if(checkSudoku(board))
        {
            dfs(0, 0, board);
            board = tmp;
        }
        else board[0][0] = 'F';
    }
    void dfs(int n, int m, vector<vector<char>>& board)
    {
        if(m==9)
            n++,m = 0;
        if(n == 9)
        {
            tmp = board;
            return ;
        }
        if(mark) return ;

        if(board[n][m] != '.')
        {
            dfs(n, m+1, board);
        }
        else for(int j = 1; j<=9; j++)
            {
                if(!vis[n/3*3+m/3][j] && !col[m][j] && !row[n][j])
                {
                    row[n][j] = vis[n/3*3+m/3][j] = col[m][j] = true;
                    board[n][m] = j + '0';
                    dfs(n, m+1, board);
                    row[n][j] = vis[n/3*3+m/3][j] = col[m][j] = false;
                    board[n][m] = '.';
                }
            }
    }
    bool checkSudoku(vector<vector<char>>& board)
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
