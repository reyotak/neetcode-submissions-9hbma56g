// similar to b-search

// the smaller one is the one with a bigger one on left
// smaller one in right

// l = 0, r = nums.size()
// while l <= r
// get the middle one
// if m > r, smaller is on the right of m
// move l to m + 1
// if m < r
// move r to m - 1
// min = r
// return min 


class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {

            int m = (r + l) / 2;

            //std::cout << "r: " << r  << " l: " << l << " m: " << m << std::endl;
            if (nums[m] >= nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }

        }

        return nums[l];
    }
};
