class Solution {
    vector<int>w;
public:
    Solution(vector<int>& w) {
        for(int i=1;i<w.size();i++)w[i]+=w[i-1];
        this->w=w;
    }
    
    int pickIndex() {
        int cSum=rand()%w.back();
        return upper_bound(w.begin(),w.end(),cSum)-w.begin();
        // int i=0,j=w.size()-1;
        // while(i<j){
        //     int mid=i+(j-i)/2;
        //     if(w[mid]==cSum)return mid;
        //     else if(w[mid]<cSum)i=mid+1;
        //     else j=mid;
        // }
        // return j;

        // for(int i=0;i<w.size();i++){
        //     if(w[i]/w.back()==cSum)return i;
        // }
        //return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */