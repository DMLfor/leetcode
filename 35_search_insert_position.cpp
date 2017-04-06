//binary_search
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        while(l<=r)
        {
            mid = (l+r)>>1;
            if(nums[mid] >= target)
                r = mid - 1;
            else l = mid + 1;
        }
        return max(l, 0);
    }
};
