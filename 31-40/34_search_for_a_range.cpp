//可以用c++的lower_bound()和upper_bound()直接做
//这里我自己写了二分来返回第一个target的下标和最后一个target的位置
class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if(nums.size() == 0) return {-1, -1};
        vector<int> ans;
        ans.push_back(my_lower_bound(0, nums.size()-1, target, nums));
        ans.push_back(my_upper_bound(0, nums.size()-1, target, nums));
        return ans;
    }
    int my_lower_bound(int l, int r, int target, vector<int>& nums)
    {
        int mid, flag = 0;
        while(l<=r)
        {
            mid = (l+r)>>1;
            if(nums[mid] >= target)
            {
                r = mid - 1;
                if(nums[mid] == target)
                    flag = 1;
            }
            else l = mid + 1;
        }
        if(flag)
            return l;
        return -1;
    }
    int my_upper_bound(int l, int r, int target, vector<int>& nums)
    {
        int mid, flag = 0;
        while(l<=r)
        {
            mid = (l+r)>>1;
            if(nums[mid] <= target)
            {
                l = mid + 1;
                if(nums[mid] == target)
                    flag = 1;
            }
            else r = mid - 1;
        }
        if(flag)
            return r;
        return -1;
    }
};
