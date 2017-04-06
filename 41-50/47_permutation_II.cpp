//这个就可以直接使用了
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector< vector<int> > ans;
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) return ans;
        do
        {
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};
