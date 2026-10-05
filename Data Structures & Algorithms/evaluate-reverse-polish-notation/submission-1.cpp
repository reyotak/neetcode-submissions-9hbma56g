class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> nums_stack;
        int result = 0;

        for (auto &token : tokens) {

            if (token == "+") {
                // get past two numbers
                if (nums_stack.size() < 2) {
                    int temp = nums_stack.top();
                    nums_stack.pop();
                    result-= temp;
                } else {
                    int temp1 = nums_stack.top();
                    nums_stack.pop();
                    int temp2 = nums_stack.top();
                    nums_stack.pop();
                    nums_stack.push(temp2 + temp1);
                }
            } else if (token == "-") {
                if (nums_stack.size() < 2) {
                    int temp = nums_stack.top();
                    nums_stack.pop();
                    result-= temp;
                } else {
                    int temp1 = nums_stack.top();
                    nums_stack.pop();
                    int temp2 = nums_stack.top();
                    nums_stack.pop();
                    nums_stack.push(temp2 - temp1);
                }

            } else if (token == "*") {
                if (nums_stack.size() < 2) {
                    int temp = nums_stack.top();
                    nums_stack.pop();
                    result-= temp;
                } else {
                    int temp1 = nums_stack.top();
                    nums_stack.pop();
                    int temp2 = nums_stack.top();
                    nums_stack.pop();
                    nums_stack.push(temp2 * temp1);
                }
            } else if (token == "/") {
                if (nums_stack.size() < 2) {
                    int temp = nums_stack.top();
                    nums_stack.pop();
                    result-= temp;
                } else {
                    int temp1 = nums_stack.top();
                    nums_stack.pop();
                    int temp2 = nums_stack.top();
                    nums_stack.pop();
                    nums_stack.push(temp2 / temp1);
                }
            } else {
                nums_stack.push(std::stoi(token));
            }
        }

        return nums_stack.top();
    }
};
