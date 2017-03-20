//我们可以用dfs来构造所有的合法序列，同时我们做一个优化：
//1.对于任意字串的前缀，左括号的数量大于等于右括号的数量
//2.数量都不能超过一半
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
    void dfs(int l, int r, int n, string now)
    {
        if(l+r == 2*n)
        {
            ans.push_back(now);
            return ;
        }
        if(r+1<=l)
        {
            dfs(l, r+1, n, now + ')');
        }
        if(l+1<=n && l+1>=r)
        {
            dfs(l+1, r, n, now + '(');
        }
    }
};
