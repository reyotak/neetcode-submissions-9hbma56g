class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (auto &str: strs) {
            string originalStr = str;
            sort(str.begin(), str.end());
            if (anagramMap.count(str)) {
                anagramMap[str].push_back(originalStr);
            } else {
                anagramMap[str] = {originalStr};
            }
        }

        vector<vector<string>> output;

        for (auto &keyValue : anagramMap) {
            output.push_back(keyValue.second);
        }

        return output;
    }
};
