

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        for (auto &c : s) {
            s_map[c]++;
        }

        for (auto &c : t) {
            t_map[c]++;
        }

        for (auto &c: s) {
            if (s_map[c] != t_map[c]) {
                return false;
            }
        }

        for (auto &c: t) {
            if (s_map[c] != t_map[c]) {
                return false;
            }
        }

        return true;
    }
};
