class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(nums));
        size_t d = nums.size()%2;
        size_t idx = nums.size()/2;
        if(d == 1){//奇数
            return static_cast<double>(nums[idx]);
        }else{//偶数
            return (nums[idx-1] + nums[idx])/2.0;
        }
    }
};
