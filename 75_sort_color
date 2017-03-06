//计数排序
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = 0, two = 0, zero = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                zero ++;
            else if(nums[i] == 1)
                one ++;
            else 
                two ++;
        }
        int cnt = 0;
        while(zero)
        {
            nums[cnt++] = 0;
            zero --;
        }
        while(one)
        {
            nums[cnt++] = 1;
            one --;
        }
        while(two)
        {
            nums[cnt++] = 2;
            two --;
        }
    }
};
