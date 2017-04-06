//用一个非常暴力的方法，直接枚举起点，然后枚举字串看是否符合
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt, tmp;
        vector<int> ans;
        int len = words[0].size(), n = words.size();
        for(auto str : words)
            cnt[str] ++;
        for(int i = 0; i<s.size()-n*len+1; i++)
        {
            tmp.clear();
            int j = 0;
            for(; j<n; j++)
            {
                string sub = s.substr(i+j*len, len);
                if(cnt.count(sub) != 0)
                {
                    tmp[sub]++;
                    if(tmp[sub] > cnt[sub]) break;
                }
                else break;
            }
            if(j == n) ans.push_back(i);
        }
        return ans;
    }
};
