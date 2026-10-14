// need to check the ones in front if block the one in back
// t0 = 2s
// t1 = 4.5s
// t2 = 10s
// t3 = 3s


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        std::vector<std::pair<int,int>> pos_speed;
        
        for (int i = 0; i < position.size(); i++) {
            pos_speed.push_back({position[i], speed[i]});
        }

        std::sort(pos_speed.begin(), pos_speed.end(), std::greater<std::pair<int,int>>());

        std::stack<pair<int,int>> stck;
        int res = 0;

        for (auto &p : pos_speed) {

            if (stck.empty()) {
                stck.push(p);
                continue;
            }

            // if the one in the stack (front) is slower, it will block the one behind
            // it will create there a car fleet blocked by the slower one
            // if is faster, pop it from stack and increase the output

            double time_1, time_2;
            time_1 = (target - p.first) / (double) p.second;
            time_2 = (target - stck.top().first) / (double) stck.top().second;

            if (time_1 <= time_2) {

            } else {
                stck.push(p);
            }
        }

        return stck.size();
    }
};
