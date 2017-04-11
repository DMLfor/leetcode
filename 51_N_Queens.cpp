//dfs暴力搞
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> str;
        string s = "";
        int vis[5][20];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i<n; i++)
            s += '.';
        for(int i = 0; i<n; i++)
        {
            str.push_back(s);
        }
        dfs(0, ans, str, vis, n);
        return ans;
    }
private:
    void dfs(int cur, vector<vector<string>> & ans, vector<string> & str, int vis[][20], const int & n)
    {
        if(cur == n)
        {
            ans.push_back(str);
        }
        for(int i = 0; i<n; i++)
        {
            if(check(cur, i, vis, n)){
                str[cur][i] = 'Q';
                vis[0][i] = vis[1][n+cur-i] = vis[2][i+cur] = 1;
                dfs(cur+1, ans, str, vis, n);
                str[cur][i] = '.';
                vis[0][i] = vis[1][n+cur-i] = vis[2][i+cur] = 0;
            }
        }
    }
    bool check(int x, int y, int vis[][20],const  int & n)
    {
        if(vis[0][y]) return false;
        if(vis[1][n+x-y]) return false;
        if(vis[2][x+y]) return false;
        return true;
    }
};
