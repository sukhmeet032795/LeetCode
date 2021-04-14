class MyCircularQueue {
public:
    deque<int> d;
    int size, curr;
    MyCircularQueue(int k) {
        size = k;
        curr = 0;
    }
    
    bool enQueue(int value) {
        if(curr < size)
        {
            d.push_back(value);
            curr++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(curr != 0)
        {
            d.pop_front();
            curr--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(curr == 0)
            return -1;
        return d.front();
    }
    
    int Rear() {
        if(curr == 0)
            return -1;
        return d.back();
    }
    
    bool isEmpty() {
        if(curr == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(curr == size)
            return true;
        return false;
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