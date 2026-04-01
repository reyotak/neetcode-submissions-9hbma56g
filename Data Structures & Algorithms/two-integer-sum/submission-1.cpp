class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto complementMap = std::unordered_map<int, int>();

        for (int i = 0; i < nums.size(); i++) {
             if (complementMap.contains(target - nums[i])) {
                std::vector<int> output = {i, complementMap[target - nums[i]]};
                std::sort(output.begin(), output.end());
                return output;
            }
            complementMap[nums[i]] = i;
        }
    }
};
