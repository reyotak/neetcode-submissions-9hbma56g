// Use a stack to push opens and pop when closing

class Solution {
public:
    bool isValid(string s) {
        std::vector<char> c_stack;
        for (auto &c : s) {
            if (c == '(' || c == '[' || c == '{') {
                c_stack.push_back(c);
            } else if (c_stack.size() == 0) {
                return false;
            } else {
                char temp = c_stack[c_stack.size() - 1];
                c_stack.pop_back();
                if ((c == ')' && temp != '(') ||
                    (c == '}' && temp != '{') ||
                    (c == ']' && temp != '[')) {
                    return false;
                } 
            }
        }
        return c_stack.size() == 0;
    }
};
