class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> n_map;
        for (int i = 0; i < nums.size(); i++) {

            if (n_map.count(target - nums[i])) {
                return {n_map[target - nums[i]] , i};
            }

            n_map[nums[i]] = i;
        }
        return {};
    }
};
