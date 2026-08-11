// criar um hash map num -> quantidade
// criar uma fila de prioridade (prioridade baseado no count)
// pra cada key do hash map, inserir na fila de prioridade
// pegar k elementos da fila de prioridade

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map;
        for (auto &num : nums) {
            freq_map[num]++;
        }
        std::priority_queue<pair<int, int>> heap;
        for (auto& entry : freq_map) {
            heap.push({entry.second, entry.first});
        }

        std::vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
