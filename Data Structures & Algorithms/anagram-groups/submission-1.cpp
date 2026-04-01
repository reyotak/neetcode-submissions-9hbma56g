class Solution {
public:

    string createAlphabetMap(string &str) {
        auto output = std::vector<int>(27);

        for (auto &c : str) {
            int index = c - 'a';
            output[index]++;
        }

        stringstream ss;

        for (int i = 0; i < output.size(); i++) {
            int n = output[i];
            for (int k = 0; k < n; k++) {
                ss << char('a' + i);
            }
        }
        return ss.str();
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > anagramMap;

        for (auto &str: strs) {
            string alphabetMap = createAlphabetMap(str);
            if (anagramMap.count(alphabetMap)) {
                anagramMap[alphabetMap].push_back(str);
            } else {
                anagramMap[alphabetMap] = {str};
            }
        }

        vector<vector<string>> output;
        for (auto &keyValue : anagramMap) {
            output.push_back(keyValue.second);
        }
        return output;
    }
};
