/* Create a map with sorted strings -> strs index
 * For each string, sort it for a-z
 * Check if it's in the map
 * If not, add to the map with the strs index
 * Print the map using the rule: for each key print the strs[index]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto anagramMap = std::unordered_map<string, vector<string>>();
        for (auto &s : strs) {
            std::string strCopy = s; 
            sort(strCopy.begin(), strCopy.end());
            anagramMap[strCopy].push_back(s);

        }
        auto output = vector<vector<string>>();
        for (auto &keyValue : anagramMap) {
            output.push_back(keyValue.second);
        }
        return output;
    }
};
