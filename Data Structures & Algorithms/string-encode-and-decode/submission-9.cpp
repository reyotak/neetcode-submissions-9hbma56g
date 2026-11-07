

// encode list of string to a single string
// encode the string start with $ and str len
// ["Hello", "World"] -> "$5$Hello$5$World"
// for decode, we read the $(strlen)
// get the strlen next chars and save the string in a list
// return the str list

class Solution {
public:

    string encode(vector<string>& strs) {
        std::stringstream ss;

        for (auto &str : strs) {
            ss << "!" << str.size() << "!" << str;
        }

        return ss.str();
    }

    vector<string> decode(string s) {

        std::vector<std::string> res;

        for (int i = 0; i < s.size(); i++) {
            // consume the first $ sign
            i++;

            // get the len
            std::stringstream ss;
            while (s[i] != '!') {
                ss << s[i];
                i++;
            }
            int len;
            ss >> len;
            i++;

            res.push_back(s.substr(i, len));

            i += len - 1;
        }

        return res;
    }
};
