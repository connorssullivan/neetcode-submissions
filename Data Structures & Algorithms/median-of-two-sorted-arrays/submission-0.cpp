#include <vector>


class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int left = (nums1.size() + nums2.size() + 1) / 2;
        int right = (nums1.size() + nums2.size() + 2) / 2;
        return (getKth(nums1, nums1.size(), nums2, nums2.size(), left, 0, 0) +
                getKth(nums1, nums1.size(), nums2, nums2.size(), right, 0, 0)) / 2.0;
    }

private:
    double getKth(std::vector<int>& nums1, int n, std::vector<int>& nums2, int m, int k, int aStart, int bStart) {
        if (m < n)
            return getKth(nums2, m, nums1, n, k, bStart, aStart);

        if (n == 0)
            return nums2[bStart + k -1];
        
        if (k == 1)
            return std::min(nums1[aStart], nums2[bStart]);

        int i = std::min(n, k/2);
        int j = std::min(m, k/2);

        if (nums1[aStart + i - 1] > nums2[bStart + j - 1])
            return getKth(nums1, n, nums2, m - j, k - j, aStart, bStart + j);
        else 
            return getKth(nums1, n-i, nums2, m, k - i, aStart+i, bStart);
    }
};
