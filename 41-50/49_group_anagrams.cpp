//stl超级好用,用一个string到multiset<string>的map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, multiset<string> > mp;
        string tmp;
        for(int i = 0; i<strs.size(); i++)
        {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].insert(strs[i]);
        }
        vector<string> res;
        for(auto & it : mp)
        {
            res.clear();
            for(auto & i : it.second)
            {
                res.push_back(i);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
