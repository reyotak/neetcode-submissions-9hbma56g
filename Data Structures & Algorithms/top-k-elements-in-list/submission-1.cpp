class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto output = std::vector<int>();
        auto frequencyMap = std::unordered_map<int, int>();
        for (auto &i : nums) {
            frequencyMap[i]++;
        }

        for (int i = 0; i < k; i++) {
            int biggest = 0;
            int add = 0;
            for (auto &keyValue : frequencyMap) {
                if (keyValue.second > biggest) {
                    biggest = keyValue.second;
                    add = keyValue.first;
                }
            }
            output.push_back(add);
            frequencyMap[add] = 0;
        }
        return output;
    }
};
