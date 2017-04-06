//和合法匹配一样，我们开一个标记数组，标记该位是否合法，最后在标记数组更新ans
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> vis(s.size(),0);
        stack<int> sta;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(')
                sta.push(i);
            else
            {
                if(!sta.empty())
                {
                    vis[i] = vis[ sta.top() ] = 1;
                    sta.pop();
                }
            }
        }
        int ans = 0, now = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(vis[i])
                now++;
            else
            {
                ans = max(now, ans);
                now = 0;
            }
        }
        ans = max(ans, now);
        return ans;
    }
};
