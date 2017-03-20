//这个数组可以看成是连个有序数组合并在一起，而且满足前面那段数字全部大于后面的那段数字
//那么我们可以二分下标，针对nums[mid]和nums[r]的大小关系来判断target在可能在那个区间里面
//通过递归来继续二分
int my_search(int l, int r, int *nums, int target)
{
    int mid = (l+r)>>1;
    if(l <= r)
    {
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
        {
            if(nums[mid] > nums[r])
            {
                int tmp = my_search(l, mid-1, nums, target);
                if(tmp != -1) return tmp;
                else
                {
                    return my_search(mid+1, r, nums, target);
                }
            }
            else return my_search(l, mid-1, nums, target);
        }
        else
        {
            if(nums[mid] > nums[r])
                return my_search(mid+1, r, nums, target);
            else
            {
                int tmp = my_search(l, mid-1, nums, target);
                if(tmp != -1) return tmp;
                else
                {
                    return my_search(mid+1, r, nums, target);
                }
            }
        }
    }
    return -1;
}
int search(int* nums, int numsSize, int target)
{
    return my_search(0, numsSize-1, nums, target);
}
