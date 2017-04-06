//使用next_permutation需要预排序
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > ans;
        //sort(nums.begin(), nums.end());
        dfs(0, nums.size()-1, nums, ans);
        return ans;
    }
    void dfs(int l, int r, vector<int>& nums, vector<vector<int>> & ans)
    {
        if(l == r)
        {
            ans.push_back(nums);
           // return ;
        }
        for(int i = l; i<=r; i++)
        {
            swap(nums[i], nums[l]);
            dfs(l+1, r, nums, ans);
            swap(nums[i], nums[l]);
        }
    }
};
