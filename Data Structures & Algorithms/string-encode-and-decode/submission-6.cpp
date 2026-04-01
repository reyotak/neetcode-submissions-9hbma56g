class Solution {
public:

    string encode(vector<string>& strs) {
        // first read a number with the str len which is before a #
        // if not a number, str finshed
        auto ss = std::stringstream();
        for (auto &s : strs) {
            ss << s.size();
            ss << '#';
            ss << s;
        }
        return ss.str();
    }

    vector<string> decode(string s) {
        auto output = vector<string>();
        for (int i = 0; i < s.size(); i++) {
            // consume the len and the string
            
            // get the number until finding #
            std::stringstream lenStr;
            while (s[i] != '#') {
                lenStr << s[i];
                i++;
            }

            // convert string to int
            int len;
            lenStr >> len;

            // add the string to the list
            auto str = s.substr(i + 1, len);
            output.push_back(str);
            i += len;
        }
        return output;
    }
};