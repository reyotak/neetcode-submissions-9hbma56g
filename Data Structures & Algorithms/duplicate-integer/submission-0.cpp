class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        auto m = std::unordered_map<int, bool>();
        for (auto &num : nums) {
            if (m.contains(num)) {
                return true;
            } else {
                m[num] = true;
            }
        }
        return false;
    }
};