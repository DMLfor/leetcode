class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int id = 0;
        if(nums.size() == 0) return 0;
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i] != nums[id])
                nums[++id] = nums[i];  
        }
        return id+1;
    }
};
