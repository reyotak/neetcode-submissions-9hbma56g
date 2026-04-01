class Solution {
public:
    typedef std::unordered_map<char, unsigned int> mp;
    
    void fillMap(string &s, mp &m) {
        for (auto &c : s) {
            if (m.contains(c)) {
                m[c]++;
            } else {
                m[c] = 1;
            }
        }
    }

    bool compareMaps(mp &m1, mp &m2) {
        for (auto &p : m1) {
            if (!m2.contains(p.first) || m2[p.first] != p.second) {
                return false;
            }
        }
        return true;
    }

    bool isAnagram(string s, string t) {
        auto s_map = mp();
        auto t_map = mp();
        fillMap(s, s_map);
        fillMap(t, t_map);
        bool status = compareMaps(s_map, t_map);
        status &= compareMaps(t_map, s_map);
        return status;
    }
};
