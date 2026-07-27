// create a map of string -> string array
// for each str in strs
// sort str
// add to a map of key == sort str value == str
// for each key, add the value to an array of string array

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> umap;
        for (auto &str : strs) {
            string str_copy = str;
            sort(str_copy.begin(), str_copy.end());
            umap[str_copy].push_back(str);
        }
        vector<vector<string>> output;
        for (auto &keyValue : umap) {
            output.push_back(keyValue.second);
        }
        return output;
    }
};
