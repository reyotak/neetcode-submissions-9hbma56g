class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> frequencyMap;
        for (auto &num : nums) {
            frequencyMap[num]++;
        }

        vector<pair<int, int>> frequencyVector;

        for (auto &freq : frequencyMap) {
            frequencyVector.push_back(freq);
        }

        auto greaterLambda = [](pair<int, int> a, pair <int, int> b) {return a.second > b.second;};

        sort(frequencyVector.begin(), frequencyVector.end(), greaterLambda);

        vector<int> output;

        for (int i = 0; i < k; i++) {
            output.push_back(frequencyVector[i].first);
        }

        return output;
    }
};
