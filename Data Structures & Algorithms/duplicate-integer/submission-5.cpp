// create an unordered set
// add value to the set
// if value is in the set, return true

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> u_set;
        for (auto &num : nums) {
            if (u_set.count(num) > 0) {
                return true;
            }
            u_set.insert(num);
        }
        return false;
    }
};