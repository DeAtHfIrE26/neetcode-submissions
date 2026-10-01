class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size(), half = (m + n + 1) / 2;
        int lo = 0, hi = m;

        while (lo <= hi){
            int i = (lo + hi) / 2;
            int j = half - i;

            int L1 = i ? nums1[i-1] : INT_MIN, R1 = i < m ? nums1[i] : INT_MAX;
            int L2 = j ? nums2[j-1] : INT_MIN, R2 = j < n ? nums2[j] : INT_MAX;

            if (L1 > R2) hi = i - 1;
            else if (L2 > R1) lo = i + 1;
            else{
                if ((m+n) & 1) return max(L1,L2);
                return (max(L1,L2) + min(R1,R2)) / 2.0;
            }
        }
        return 0.0;
    }
};
