class RangeModule {
public:
    vector<int> ranges;
    vector<int>::iterator it_left, it_right;
    int pos_left, pos_right;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        it_left = lower_bound(ranges.begin(), ranges.end(), left);
        it_right = upper_bound(it_left, ranges.end(), right);
        pos_left = it_left - ranges.begin();
        pos_right = it_right - ranges.begin();

        ranges.erase (it_left, it_right);
        
        if ( pos_left % 2 == 0 ) { 
            ranges.insert (ranges.begin() + pos_left, left); 
            pos_left++;
        }
        if ( pos_right % 2 == 0 ) { 
            ranges.insert (ranges.begin() + pos_left, right); 
        }
    }
    
    bool queryRange(int left, int right) {
        it_left = upper_bound(ranges.begin(), ranges.end(), left);
        it_right = lower_bound(it_left, ranges.end(), right);
        if ( it_left == it_right && 
            (it_left - ranges.begin()) % 2 == 1 ) 
        { return true; }
        return false; 
    }
    
    void removeRange(int left, int right) {
        it_left = lower_bound(ranges.begin(), ranges.end(), left);
        it_right = upper_bound(it_left, ranges.end(), right);
        pos_left = it_left - ranges.begin();
        pos_right = it_right - ranges.begin();

        ranges.erase (it_left, it_right);

        if ( pos_left % 2 == 1 ) { 
            ranges.insert (ranges.begin() + pos_left, left); 
            pos_left++;
        }
        if ( pos_right % 2 == 1 ) { 
            ranges.insert (ranges.begin() + pos_left, right); 
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */