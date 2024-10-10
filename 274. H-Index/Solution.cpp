class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> v(n+1,0);
        for(int i=0;i<n;i++){
            int idx=min(citations[i],n);
            v[idx]++;
        }
        int hIdx=0;
        for(int i=n;i>=1;i--){
            hIdx+=v[i];
            if(hIdx>=i)return i;
        }
        return 0;
    }
};