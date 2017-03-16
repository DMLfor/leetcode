//先建立一个roman to int 的映射表，然后进行判断累加

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char , int> umap
        {
            {'I', 1}, {'V', 5},
            {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500},
            {'M', 1000}
        };
        int ans = 0;
        for(int  i = 0; i<s.size(); i++)
        {
            if(i < s.size() - 1 && umap[ s[i] ] < umap[ s[i+1] ])
            {
                ans += umap[ s[i+1] ] - umap[ s[i] ];
                i++;
            }
            else ans += umap[ s[i] ];
        }
        return ans;
    }
};
