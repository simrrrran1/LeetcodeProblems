class MovingAverage {
public:
    int size;
    queue<int> q;
    double sum;
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        if(q.size() == size){
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */