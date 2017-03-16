//和3 Sum 一样，只不过是每次得到一个值都去更新答案
class Solution {
public:
    int ans = INT_MAX;
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            twoSum(i+1, nums.size()-1, target - nums[i], nums);
        }
        return target - ans;
    }
    void twoSum(int l, int r, int target, vector<int>& nums)
    {
        while(l < r)
        {
            if(nums[l] + nums[r] <= target)
            {
                if(abs(ans) > abs(target - nums[l] - nums[r]))
                    ans = target - nums[l] - nums[r];
                    l++;
            }
            else
            {
                if(abs(ans) > abs(target - nums[l] - nums[r]))
                    ans = target - nums[l] - nums[r];
                r--;
            }
        }
    }
};
