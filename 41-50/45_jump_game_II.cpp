//bfs O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size()-1, step = 0;
        while(r <= n-1)
        {
            step ++;
            int maxjump = r + 1;
            for(int i = l; i<=r; i++)
            {
                if(nums[i] + i >= n) return step;
                maxjump = max(maxjump, nums[i]+i);
                
            }
            l = r + 1;
            r = maxjump;
        }
        return step;
    }
};
