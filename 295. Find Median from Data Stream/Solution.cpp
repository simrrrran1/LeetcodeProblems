class MedianFinder {
public:
    priority_queue<int> maxHeap; // smaller nos
    priority_queue<int,vector<int> , greater<int>> minHeap; // larger nos
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if((maxHeap.empty() && minHeap.empty()) || num < maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        if(maxHeap.size() > 1+minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > 1+maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        return;
    }
    
    double findMedian() {
        
        if(minHeap.size() == maxHeap.size()){
            return (double) ((minHeap.top() + maxHeap.top())/2.0);
        }
        else if(minHeap.size() < maxHeap.size()){
            return maxHeap.top();
        }
        else if(minHeap.size() > maxHeap.size()){
            return minHeap.top();
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */