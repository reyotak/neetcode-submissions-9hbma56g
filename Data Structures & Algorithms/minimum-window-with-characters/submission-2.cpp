// sliding window

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        int l_min = -1, r_min = -1;
        std::string min_w;

        std::unordered_map<char,int> t_map;
        for (auto &c : t) {
            t_map[c]++;
        }
        int hits = 0;

        while (r < s.size()) {

            if (t_map.count(s[r])) {
                if (t_map[s[r]] > 0) {
                    hits++;
                }
                t_map[s[r]]--;
            }


            while (hits == t.size() && l <= r) {

                if (r_min == - 1 || r_min - l_min > r - l) {
                    l_min = l;
                    r_min = r;
                }


                if (t_map.count(s[l])) {
                    t_map[s[l]]++;
                    if (t_map[s[l]] > 0) {
                        hits--;
                    }
                }

                l++;
            }

            r++;
        }
        
        if (r_min != -1) {
            min_w = s.substr(l_min, r_min - l_min + 1);
        }

        return min_w;
    }
};
