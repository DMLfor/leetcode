//和3Sum一样，不同的是前面n*n枚举出一个target
class Solution
{
public:
    vector< vector<int> > ans;
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++)
            for(int j = i+1; j<nums.size(); j++)
            {
                if((i>0 && nums[i] == nums[i-1]) || (j > i+1 && nums[j] == nums[j-1]))
                    continue;
                twoSum(j+1, nums.size()-1, nums, target - nums[i] - nums[j], i, j);
            }
            return ans;
    }
    void twoSum(int l, int r, vector<int>& nums, int target, int f, int s)
    {
        vector<int> tmp;
        while(l<r)
        {
            tmp.clear();
            if(nums[l] + nums[r] == target)
            {
                tmp.push_back(nums[f]);
                tmp.push_back(nums[s]);
                tmp.push_back(nums[l]);
                tmp.push_back(nums[r]);
                while(l<r && nums[l] == nums[l+1])
                    l++;
                while(l<r && nums[r] == nums[r-1])
                    r--;
                l++;
                r--;
                ans.push_back(tmp);
            }
            else if(nums[l] + nums[r] < target)
                l++;
            else r--;
        }
    }
};
