

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_mask[30] = {0};
        int t_mask[30] = {0};

        for (auto &c : s) {
            s_mask[c - 'a']++;
        }

        for (auto &c : t) {
            t_mask[c - 'a']++;
        }

        for (int i = 0; i < 27; i++) {
            if (s_mask[i] != t_mask[i]) {
                return false;
            }
        }

        return true;
    }
};
