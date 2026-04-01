class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freqMap;
        for (auto &num : nums) {
            freqMap[num]++;
        }

        auto freqBucket = vector<vector<int>>(nums.size() + 1);

        for (auto &freq : freqMap) {
            freqBucket[freq.second].push_back(freq.first);
        }

        vector<int> output;
        for (int i = nums.size(); i > 0; i--) {
            for (auto &value : freqBucket[i]) {
                output.push_back(value);
                if (output.size() == k) {
                    return output;
                }   
            }
        }

        return output;
    }
};
