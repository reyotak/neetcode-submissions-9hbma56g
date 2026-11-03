// do small tweak version binary search
// l = 0, r = nums.size() - 1;
// while l <= r
// m = (l + r) / 2

// if nums[l] > nums[m]
// in between the value is reduced from max to min
// so we need to check the left part
// r = m - 1

// else if nums[m] > nums[r]
// in between the value is reduced from max to min
// so we need to check the right part
// l = m + 1

// else it's in order, we can return the nums[l]
// return l

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;

        while (r - l > 1) {

            int m = (l + r) / 2;

            if (nums[l] > nums[m]) {
                r = m;
            } else if (nums[m] > nums[r]) {
                l = m;
            } else {
                return nums[l];
            }
        }

        return std::min(nums[l], nums[r]);
    }
};
