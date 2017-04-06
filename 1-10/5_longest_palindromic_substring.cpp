//manacher算法,O(N)求解
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int l = s.size();
        int len[2*l+10], id = 0;
        char ss[2*l+ 10];
        for(int i = l; i>=0; i--)
        {
            ss[i*2 + 2] = s[i];
            ss[i*2 + 1] = '#';
        }
        ss[0] = '*';
        int maxx = 0, maxi;
        memset(len, 0, sizeof(len));
        for(int i = 1; i<=2*l; i++)
        {
            if(id + len[id] > i)
                len[i] = min(len[2*id-i], len[id] + id - i);
            while(ss[i+len[i]] == ss[i-len[i]]) len[i] ++;
            if(len[i] + i > len[id] + id)
                id = i;
            if(maxx < len[i])
                maxx = len[i], maxi = i;
        }
        string ans = "";
        for(int i = maxi - maxx + 1; i<=maxi + maxx-1; i++)
            if(ss[i]!='#')
                ans += ss[i];
        //cout<<maxi - len[maxi]+1<<endl;
        // cout<<ans<<endl;
        return ans;
    }
};
