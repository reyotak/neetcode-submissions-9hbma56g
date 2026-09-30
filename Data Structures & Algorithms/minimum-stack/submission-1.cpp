class MinStack {

private:
    std::stack<int> data;
    std::map<int, int> min_map;

public:
    MinStack() {}
    
    void push(int val) {
        data.push(val);
        min_map[val]++;
    }
    
    void pop() {
        int temp = data.top();
        data.pop();
        min_map[temp]--;
        if (min_map[temp] == 0) {
            min_map.erase(temp);
        }
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_map.begin()->first;
    }
};
