class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, l = 0, r = height.size() - 1, minx = 0, now = 0;
        while(l<r)
        {
            if(height[l] < height[r])
            {
                now = height[l];
                l++;
            }
            else 
            {
                now = height[r];
                r--;
            }
            if(now > minx)
                minx = now;
            ans += minx - now;
        }
        return ans;
    }
};
