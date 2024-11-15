/**
 * Two pointers and two values
 * 
 * return median, O(1) space complexity
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;

        int m1 = 0, m2 = 0;

        int total = nums1.size() + nums2.size();

        for (int count = 0; count <= total / 2; count++) {
            m1 = m2;
            if (i >= nums1.size()) {
                m2 = nums2[j++];
                continue;
            }
            if (j >= nums2.size()) {
                m2 = nums1[i++];
                continue;
            }

            if (nums1[i] <= nums2[j]) {
                m2 = nums1[i++];
            } else {
                m2 = nums2[j++];
            }
        }

        if (total % 2 == 0) {
            return (double(m1) + double(m2)) / 2.0;
        }
        return m2;
    }
};