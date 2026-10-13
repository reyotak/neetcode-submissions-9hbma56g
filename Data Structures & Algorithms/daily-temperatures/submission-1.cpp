// create a priority queue {value, index} with smaller in front
// if new value is higher than the on in the top of queue, pop it
// pop it while the new value is smaller
// add in the vector the index diff
// add in the queue
// in the end, pop all values and add zeros


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

/*
        auto func = [](std::pair<int,int> a, std::pair<int,int> b) {
            return a.first > b.first;
        };
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,
        decltype(func)> pq(func);
*/
        stack<pair<int, int>> pq; // pair: {temp, index}

        std::vector<int> res;
        res.resize(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {

            while (!pq.empty() && pq.top().first < temperatures[i]) {
                auto temp_index = pq.top().second;
                res[temp_index] = i - temp_index;
                pq.pop();
            }

            pq.push({temperatures[i], i});
        }

        while (!pq.empty()) {
            auto temp_index = pq.top().second;
            res[temp_index] = 0;
            pq.pop();
        }

        return res;
    }
};
