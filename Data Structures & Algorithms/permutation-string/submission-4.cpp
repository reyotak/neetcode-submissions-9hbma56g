// sliding window

// X start l = r = 0
// X while r < s2 size
// X if s1 contains s2[r]
// X remove s2[r] from s1
// X r go next
// X if does not contain
// X add s2[l] back to s1
// X l go next
// X check if contain until l == r
// X if contains remove s2[r] from s1
// X r go next
// X if not l go next
// X r go next
// X go back to start of the loop while


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> s_map;

        for (auto &c : s1) {
            s_map[c]++;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); r++) {

            if (s_map.count(s2[r]) && s_map[s2[r]] > 0) {
                s_map[s2[r]]--;

                if ((r - l) + 1 == s1.size()) {
                    return true;
                }

            } else {
                while (s_map[s2[r]] <= 0 && l < r) {
                    s_map[s2[l]]++;
                    l++;
                }

                if (s_map[s2[r]] > 0) {
                    s_map[s2[r]]--;
                } else {
                    l++;
                }
            }

        }

        return false;
    }
};
