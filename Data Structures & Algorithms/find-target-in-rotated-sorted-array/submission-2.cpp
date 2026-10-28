// binary search

// l = 0, r = nums.size()
// while r >= l
// m = (r + l) / 2
// if nums[m] == target return m
// if nums[l] <= nums[m]
// check if value is between nums[l] and nums[m]
// if  yes r = m - 1
// if not l = m + 1
// if nums[l] > nums[m]
// check if value is between nums[m] and nums[r]
// if yes l = m + 1
// if not r = m - 1
// if exit while, return -1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (r >= l) {

            int m = (r + l) / 2;

            if (nums[m] == target) {
                return m;
            }

            if (nums[l] <= nums[m]) {

                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};
