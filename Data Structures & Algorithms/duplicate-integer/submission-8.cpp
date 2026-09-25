class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> nums_set;
        for (auto &n : nums) {
            if (nums_set.count(n) != 0) {
                return true;
            }
            nums_set.insert(n);
        }
        return false;
    }
};