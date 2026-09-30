class MyCircularQueue {
    
private:
    std::unique_ptr<int[]> data;
    int head;
    int tail;
    int count;
    int max_size;
public:
    MyCircularQueue(int k) :
        head(0),
        tail(-1),
        count(0),
        max_size(k) {
        data = make_unique<int[]>(k);
    };
    
    bool enQueue(int value) {
        if (count == max_size) {
            return false;
        }
        count++;
        tail++;
        tail = tail % max_size;
        data[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if (count == 0) {
            return false;
        }
        count--;
        head++;
        head = head % max_size;
        return true;
    }
    
    int Front() {
        return count == 0 ? -1 : data[head];
    }
    
    int Rear() {
        return count == 0 ? -1 : data[tail];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == max_size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */