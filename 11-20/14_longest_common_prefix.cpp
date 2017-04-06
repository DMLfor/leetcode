//直接暴力

class Solution {

public:

    string longestCommonPrefix(vector<string>& strs) {

        string ans ="";

        if(strs.size()<1)

        return "";

        for(int i = 0; i<strs[0].size(); i++)

        {

            if(check(i, strs))

                ans.push_back(strs[0][i]);

            else break;

        }

        return ans;

    }

    bool check(int id, vector<string>& strs)

    {

        for(int i = 1; i<strs.size(); i++)

        {

            if(id > strs[i].size() || strs[i][id] != strs[0][id])

                return false;

        }

        return true;

    }

};
