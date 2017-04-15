class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size()-1, step = 0;
        if(nums.size()==1) return true;
        while(r <= n-1)
        {
            step ++;
            int maxjump = r;
            for(int i = l; i<=r; i++)
            {
                if(nums[i] + i >= n) return true;
                maxjump = max(maxjump, nums[i]+i);
                
            }
            l = r;
            r = maxjump;
            if(l==r) return false;
        }
        return false;
    }
};
