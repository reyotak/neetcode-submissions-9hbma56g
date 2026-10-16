class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1;

        while (l < r) {

            // get the value in the middle
            int m = (l + r) / 2;

            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return nums[l] == target ? l : -1;
    }
};
