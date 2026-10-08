

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_mask[27];
        int t_mask[27];

        for (auto &c : s) {
            s_mask[c - 'a']++;
        }

        for (auto &c : t) {
            t_mask[c - 'a']++;
        }

        for (int i = 0; i < 27; i++) {

            std::cout << "s_mask : " << s_mask[i] << " t_mask: " << t_mask[i] <<std::endl;

            if (s_mask[i] != t_mask[i]) {
                return false;
            }
        }

        return true;
    }
};
