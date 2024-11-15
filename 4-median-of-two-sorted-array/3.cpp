class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            findMedianSortedArrays(nums2, nums1);
        }

        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;
        int left = 0;
        int right = nums1.size();
        int i = 0;   // 不包含
        int j = 0;   // 不包含

        while (left <= right) {
            i = (left+right) / 2;
            j = half - i;

            if (i < right && nums2[j-1] > nums1[i]) {
                left = i + 1;
            } else if (i > left && nums1[i-1] > nums2[j]) {
                right = i - 1;
            } else {
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j-1];
                } else if (j == 0) {
                    maxLeft = nums1[i-1];
                } else {
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                }

                if (total % 2 == 1) {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == nums1.size()) {
                    minRight = nums2[j];
                } else if (j == nums2.size()) {
                    minRight = nums1[i];
                } else {
                    minRight = min(nums2[j], nums1[i]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }

        //     // if (nums1[aMid] <= nums2[bMid+1] && nums2[bMid] <= nums1[aMid+1]) {
        //     //     break;  // 找到正確的 partition
        //     // } else if (nums1[aMid] > nums2[bMid+1]) {
        //     //     r = aMid;
        //     // } else if (nums2[bMid] > nums1[aMid+1]) {
        //     //     l = aMid + 1;
        //     // }
        // }

        // // cout << aMid << " " << bMid << endl;
        return 0;
    }
};