//双指针法（尺取法）
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int vis[200] = {0};
        int l = 0, r = 0, ans = 0;
        while(l < s.size())
        {
            while(vis[s[r]] == 0 && r<s.size())
            {
                vis[s[r]] ++;
                r++;
            }
            ans = max(r - l, ans);
            vis[s[l]]--;
            l++;
        }
        return ans;
    }
};
