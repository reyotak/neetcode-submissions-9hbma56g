class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        auto q = std::deque<int>();
        auto output = std::vector<int>();

        while (r < nums.size()) {
            while (q.size() != 0 && nums[r] > nums[q[q.size() - 1]]) {
                q.pop_back();
            }
            q.push_back(r);

            if (l > q[0]) {
                q.pop_front();
            }

            if (r + 1 >= k) {
                output.emplace_back(nums[q[0]]);
                l+= 1;
            }
            r += 1;
        }
        return output;
    }
};
