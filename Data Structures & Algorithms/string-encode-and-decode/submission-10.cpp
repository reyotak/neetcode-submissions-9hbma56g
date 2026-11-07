// encode string
// encode to 5!Hello5!World

// decode string from 5!Hello5!World
// Hello World



class Solution {
public:

    string encode(vector<string>& strs) {
        std::string res;
        for (auto &s : strs) {
            res+= to_string(s.size());
            res+= "!";
            res+= s;
        }
        return res;
    }

    vector<string> decode(string s) {
        std::string_view s_view(s);
        std::vector<std::string> res;

        for (int i = 0; i < s.size(); i++) {

            // read str len
            int k = i;
            while (s[i] != '!') {
                i++;
            }
            int len = stoi(std::string(s_view.substr(k, i - k)));

            // skip the !
            i++;

            // add the str to str list
            res.emplace_back(s_view.substr(i, len));
            i+=  len - 1;
        }

        return res;
    }
};
