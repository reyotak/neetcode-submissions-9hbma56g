class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mp_nums_index;
        // for each n, add it on the map with it index
        // check if the map contains the two sum part
        std::vector<int> output(2);
        for (int i = 0; i < nums.size(); i++) {
            auto two_sum_ptr =  mp_nums_index.find(target - nums[i]);
            if (two_sum_ptr != mp_nums_index.end()) {
                // found the two sum part
                output[0] = two_sum_ptr->second;
                output[1] = i;
                return output;
            }
            mp_nums_index[nums[i]] = i;
        }
        return output;
    }
};
