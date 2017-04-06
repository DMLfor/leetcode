//两种解法，一种是dp，一种式迭代回溯
//解法一：迭代回溯
bool isMatch(const char *s, const char *p)
{
    char *ptr_s = s, *ptr_p = NULL;        //建立两个指针记录回溯地点
    while(*s != '\0')
    {
        if(*s == *p || *p == '?')          //此时为直接匹配到
            s++, p++;
        else if(*p == '*')                //此时为认为'*'为空串
            ptr_s = s, ptr_p = p ++;      //记录指针记录位置,p跳至下一个
        else if(ptr_p != NULL)           //下一个匹配失败,跳回，并认为匹配为'*'
            s = ++ptr_s, p = ptr_p + 1;  //的字串
        else return false;
    }
    while(*p == '*')                     //此时p可能为'*'未结束
        p++;
    return *p == '\0';
}
//解法二：dp  dp[i][j] 表示s串前i个匹配了p串前j个 O(s*p)
bool isMatch(const char *s, const char *p)
{
    bool dp[1100][1100];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; p[i]; i++)
        if(p[i] == '*')
            dp[0][i+1] = 1;
        else break;
    int n = strlen(s), m = strlen(p);
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
        {
            if((s[i-1] == p[j-1] || p[j-1] == '?')&& dp[i-1][j-1])
                dp[i][j] = 1;
            else if(p[j-1] == '*')
            {
                dp[i][j] |= (dp[i-1][j] | dp[i-1][j-1] | dp[i][j-1]);
            }
        }
    return dp[n][m];
}



