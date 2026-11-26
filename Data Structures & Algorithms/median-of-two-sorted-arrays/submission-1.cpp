// sum the size of both array
// get the size of the left part
// get the left part of the A array (b-search)
// get the left part of the B array (size left part totat - size left part A)
// check if boundaries are ok (last from A >= last from B, last + 1 from B <= last from A)
// if not, b-search A array update m (update left part A)
// update left part B
// do the check again

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int leftTotal = (m + n + 1) / 2;

        int l = 0;
        int r = m;

        while (l <= r) {

            int i = (r + l) / 2;
            int j = leftTotal - i;

            int nums1Left = i > 0 ? nums1[i - 1] : INT_MIN;
            int nums1Right = i < m ? nums1[i] : INT_MAX;
            int nums2Left = j > 0 ? nums2[j - 1] : INT_MIN;
            int nums2Right = j < n ? nums2[j] : INT_MAX;

            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                if ((m + n) % 2) {
                    return max(nums1Left, nums2Left);
                }
                return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
            } else if (nums1Left > nums2Right) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return 0.0;
    }
};
