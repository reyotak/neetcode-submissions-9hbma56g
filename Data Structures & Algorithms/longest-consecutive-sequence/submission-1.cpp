class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // we can have a unordered_map with key num and value of the sequence len
        // populate this map
        // iterate through the queue from the values that are the starters

        std::unordered_map<int, int> nums_map;
        int longest = 0;

        for (auto &n : nums) {
            if (nums_map[n] == 0) {
                nums_map[n] = nums_map[n - 1] + nums_map[n + 1] + 1;
                nums_map[n - nums_map[n - 1]] = nums_map[n];
                nums_map[n + nums_map[n + 1]] = nums_map[n];
                longest = std::max(longest, nums_map[n]);
            }
        }
       return longest;
    }
};
