class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        std::unordered_map<char, int> char_mp;
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            // find the initial sliding window size
            if (char_mp.count(s[r])) {
                l = std::max(char_mp[s[r]] + 1, l);
            }
            char_mp[s[r]] = r;
            res = std::max(res, r - l + 1);
        }
        return res;
    }
};