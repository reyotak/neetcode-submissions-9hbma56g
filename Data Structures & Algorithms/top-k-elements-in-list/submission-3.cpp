class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> frequencyMap;
        for (auto &num : nums) {
            frequencyMap[num]++;
        }

        auto greaterLambda = [](pair<int, int> a, pair <int, int> b) {return a.second > b.second;};

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greaterLambda)> minHeap;

        for (auto &freq : frequencyMap) {
            minHeap.push(freq);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> output;
        for (int i = 0; i < k; i++) {
            output.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return output;

    }
};
