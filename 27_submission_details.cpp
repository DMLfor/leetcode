ass Solution {

public:
    int removeElement(vector<int>& nums, int val) {
        int id = 0;
        if(nums.size() == 0) return 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] != val)
                nums[id++] = nums[i];  
        }

        return id;
    }
};
