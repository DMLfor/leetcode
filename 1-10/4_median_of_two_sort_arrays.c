int min(int a, int b)
{
    return a > b ? b : a;
}

int kth(int *nums1, int n, int *nums2, int m, int k)
{
    if(n < m)
        return kth(nums2, m, nums1, n, k);
    if(m == 0)
        return nums1[k-1];
    if(k == 1)
        return min(nums1[0],nums2[0]);
    int p = min(k/2, m);
    int o = k - p;
    if(nums1[o-1] > nums2[p-1])
        return kth(nums1, n, nums2+p, m-p, k-p);
    return kth(nums1+o, n-o, nums2, m, k-o);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int cnt = nums1Size + nums2Size;
    // cout<<get(nums1, nums1Size, nums2, nums2Size, cnt / 2)<<" "<<get(nums1, nums1Size, nums2, nums2Size, cnt/2+ 1)<<endl;
    int k = (nums1Size + nums2Size)/2;
    if(cnt % 2 == 0)
        return ((double)kth(nums1, nums1Size, nums2, nums2Size, k + 1) + kth(nums1, nums1Size, nums2, nums2Size, k))/2;
    else
        return kth(nums1, nums1Size, nums2, nums2Size, k + 1);
}
