//dfs����������40�ⲻһ���ľ��ǿ���ѡѡ���ģ��ݹ��������һ�Ϳ����ˡ�
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector< vector<int> > ans;
        set<vector<int>> s;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, tmp, 0,s);
        for(auto it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
    void dfs(vector<int>& a,int last, int target, vector<int>& tmp, int sum, set<vector<int> >& s)
    {
        if(sum == target)
        {
            s.insert(tmp);
        }
        for(int i = last+1; i<a.size(); i++)
        {
            if(sum + a[i] <= target)
            {
                tmp.push_back(a[i]);
                dfs(a, i, target, tmp, sum + a[i], s);
                tmp.pop_back();
            }
        }
    }
};
