class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int totalIgnoringZeros = 1;
        int zeroCount = 0;

        for (auto n : nums) {
            if (n != 0) {
                totalIgnoringZeros *= n;
            } else {
                zeroCount++;
            }
        }

        if (zeroCount >= 2) {
            return std::vector<int>(nums.size());
        }

        if (zeroCount == 1) {
            for (auto n : nums) {
                if (n == 0) {
                    output.push_back(totalIgnoringZeros);
                } else {
                    output.push_back(0);
                }
            }
            return output;
        }

        for (auto n : nums) {
            output.push_back(totalIgnoringZeros / n);
        }
        return output;
    }
};
