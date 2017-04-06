Solution
{
public:
    vector< vector<int> > ans;
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        if(nums.size()<3) return ans;
        for(int i = 0; i<nums.size(); i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            twoSum(i+1, nums.size()-1, i, nums);
        }
        return ans;
    }
    void twoSum(int l, int r, int target, vector<int>& nums)
    {
        vector<int> tmp;
        while(l<r)
        {
            if(nums[l] + nums[r] == -nums[target])
            {
                tmp.clear();
                tmp.push_back(nums[target]);
                tmp.push_back(nums[l]);
                tmp.push_back(nums[r]);
                ans.push_back(tmp);
                while(l<r && nums[l+1] == nums[l])
                    l++;
                while(l<r && nums[r-1] == nums[r])
                    r--;
                l++;
                r--;
            }
            else if(nums[l] + nums[r] < -nums[target])
                l++;
            else r--;
        }
    }
};
