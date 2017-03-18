//dfs 暴力
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> mp({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        vector<string> ans;
        dfs(0, ans, digits, "", mp);
        return ans;
    }
    void dfs(int cnt, vector<string>& ans, string& digits, string now, vector<string>& mp)
    {
        if(cnt == digits.size())
        {
            if(now.size())
                ans.push_back(now);
            return ;
        }
        int id = digits[cnt] - '0';
        for(int i = 0; i<mp[id].size(); i++)
        {
            dfs(cnt+1, ans, digits, now + mp[id][i], mp);
        }
    }
};
