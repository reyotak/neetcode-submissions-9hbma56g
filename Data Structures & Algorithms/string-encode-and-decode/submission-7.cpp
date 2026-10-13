// it will be codded to be: str len + : + str

class Solution {
public:

    string encode(vector<string>& strs) {
        std:stringstream ss;

        for (auto &str : strs) {

            // add the str len, ":" and the str 
            ss << str.size() << ":" << str;
        }

        return ss.str();
    }

    vector<string> decode(string s) {

        std::vector<string> output;
        
        for (int i = 0; i < s.size(); i++) {

            // get the str len
            int str_size;
            std::stringstream str_size_ss;
            while (s[i] >= '0' && s[i] <= '9') {
                str_size_ss << s[i];
                i++;
            }
            str_size_ss >> str_size;

            // skip the :
            i++;

            // copy the str to output
            output.push_back(s.substr(i, str_size));
            i+= str_size - 1;
        }

        return output;
    }
};
