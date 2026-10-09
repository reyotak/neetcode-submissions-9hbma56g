class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> anag_map;

        for (auto &s : strs) {
            int c_map[26] = {0};
            
            for (auto &c : s) {
                c_map[c - 'a']++;
            }

            // build string for anagram key
            std::stringstream ss_key;
            for (int i = 0; i < 26; i++) {
                ss_key << static_cast<char>('a' + i) << c_map[i];
            }

            anag_map[ss_key.str()].push_back(s);
        }

        std::vector<std::vector<std::string>> output;

        for (auto& key_value : anag_map) {
            output.emplace_back(std::move(key_value.second));
        }

        return output;
    }
};
