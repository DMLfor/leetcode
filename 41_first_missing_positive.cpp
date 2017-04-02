// 把i都放在nums[i-1]的位置，可以不断的交换，因为最差为环，复杂度还是O(n)的
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == i + 1)
                continue;
            int x = nums[i];
            while(x>=1 && x<=nums.size() && nums[x-1] != x )
                swap(x, nums[x-1]);
        }
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] != i+1) return i+1;
        }
        return nums.size() + 1;
    }
};
