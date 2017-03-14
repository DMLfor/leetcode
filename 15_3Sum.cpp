//二分查找 O(n*log(n*n))
class Solution
{
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        typedef pair<int, int> P;
        vector< pair<int, P> > two;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++)
            for(int j = i + 1; j<nums.size(); j++)
            {
                two.push_back(make_pair(nums[i] + nums[j], make_pair(i, j)));
            }

        sort(two.begin(), two.end());
        vector<vector<int> > ans;
        if(nums.size()<3) return ans;
        for(int i = 0; i<(int)nums.size(); i++)
        {
            int l = 0, r = two.size() - 1, ansl = -1, ansr,mid;
            while(l<=r)
            {
                mid = (l+r)>>1;
                if(two[mid].first  + nums[i] >= 0)
                    r = mid - 1, ansl = mid;
                else l = mid + 1;

            }
            if(two[l].first + nums[i] == 0) ansl = l;
            l = 0, r = two.size() - 1, ansr = -1;
            while(l<=r)
            {
                mid = (l+r)>>1;
                if(two[mid].first <= -nums[i])
                    l = mid + 1, ansr = mid;
                else r = mid - 1;
            }
            if(two[r].first + nums[i] == 0) ansr = r;
            vector<int> tmp;
            if(ansl !=-1 && ansr!=-1)
                for(int j = ansl; j<=ansr; j++)
                {
                    tmp.clear();
                    int idx = two[j].second.first, idy = two[j].second.second;
                    if(idx != i && idy != i && i>idy)
                    {
                        tmp.push_back(nums[idx]);
                        tmp.push_back(nums[idy]);
                        tmp.push_back(nums[i]);

                    }
                    int yes = 1;
                    if(tmp.size())
                    {

                        for(int k = 0; k<ans.size(); k++)
                            if(ans[k] == tmp)
                                yes = 0;
                    }
                    if(yes && tmp.size())
                        ans.push_back(tmp);
                }

        }
        return ans;
    }
};

