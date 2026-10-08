class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> n_set;

        for (auto &n : nums) {
            if (n_set.count(n)) {
                return true;
            }
            n_set.insert(n);
        }
        return false;
    }
};