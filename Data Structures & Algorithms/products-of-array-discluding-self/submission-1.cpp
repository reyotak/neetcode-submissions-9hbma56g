class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto output = vector<int>(nums.size());
        // output vector is the prefix * postfix of i position
        
        // calculate the prefix for each num in nums
        output[0] = 1;
        for (int i = 1 ; i < nums.size(); i++) {
            output[i] = output[i - 1] * nums[i - 1]; 
        }

        // calculate the postfix and multiply by the prefix
        int postfix = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            output[i] = output[i] * postfix;
            postfix *= nums[i];
        }

        return output;
    }
};
