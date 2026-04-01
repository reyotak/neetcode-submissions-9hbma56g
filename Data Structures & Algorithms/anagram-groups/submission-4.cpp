class Solution {
public:

    string createAlphabetMap(string &str) {
        auto letters = std::vector<int>(27);

        for (auto &c : str) {
            int index = c - 'a';
            letters[index]++;
        }

        stringstream ss;
        for (auto &i : letters) {
            ss << to_string(i) << ',';
        }
        return ss.str();
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > anagramMap;

        for (auto &str: strs) {
            string alphabetMap = createAlphabetMap(str);
            anagramMap[alphabetMap].push_back(str);
        }

        vector<vector<string>> output;
        for (auto &keyValue : anagramMap) {
            output.push_back(keyValue.second);
        }
        return output;
    }
};
