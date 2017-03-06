//二分查找
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int> >p;
    p.push_back(make_pair(0, 0));
    for(int i = 0; i<nums.size(); i++)
    {
        p.push_back(make_pair(nums[i], i+1));       //二分查找需要有序，将原始序号记录，以数据大小排序
    }
    sort(p.begin()+1, p.end());                    
    vector<int> ans;
    for(int i = 1; i<=nums.size(); i++)
    {
        ans.clear();
        int l = i+1, r = nums.size(), mid;          //每次二分查找后面与该数满足target的数
        while(l<=r)
        {
            mid = (l+r)>>1;
            if(p[i].first + p[mid].first == target)
            {
                ans.push_back(p[i].second-1), ans.push_back(p[mid].second-1);
                return ans;
            }
            else if(p[i].first + p[mid].first > target)
                r = mid - 1;
            else l = mid + 1;
        }
    }
    }
};
