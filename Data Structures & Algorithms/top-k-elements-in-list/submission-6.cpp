class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> freq_map;

        for (auto &n : nums) {
            freq_map[n]++;
        }

        auto compare = 
        [](std::pair<int,int> a, std::pair<int,int> b){return a.second > b.second;};

        std::priority_queue<std::pair<int,int>,
            std::vector<std::pair<int,int>>,
            decltype(compare)>
            high_freq(compare);

        for (auto &kv : freq_map) {

            high_freq.push(kv);

            if (high_freq.size() > k) {
                high_freq.pop();
            }
        }

        std::vector<int> output;

        for (int i = 0; i < k; i++) {
            auto temp = high_freq.top();
            output.push_back(temp.first);
            high_freq.pop();
        }

        return output;
    }
};
