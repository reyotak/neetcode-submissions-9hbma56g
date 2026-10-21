class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_set<char> c_set;
        for (auto &c : s) {
            c_set.insert(c);
        }

        // for each character, check the longest repeating one
        int res = 0;
        for (auto &key : c_set) {
            std::deque<char> window;
            int count = k;
            for (auto &c : s) {

                if (c != key) {
                    count--;
                }

                window.push_back(c);

                while (count < 0) {
                    char temp = window.front();
                    if (temp != key) {
                        count++;
                    }
                    window.pop_front();
                }
                for (auto &i : window) {
                    //std::cout << i;
                }
                //std::cout << count << std::endl;
                if (count >= 0) {
                    res = std::max(res, static_cast<int>(window.size()));
                }
            }
        }

        return res;
    }
};
