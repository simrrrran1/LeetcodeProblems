class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1, 0);
        for(int i=0; i<=n; i++){
            int hammingWeight = 0;
            int x = i;
            while(x){
                hammingWeight += (x&1);
                x /= 2;
            }
            v[i] = hammingWeight;
        }

        return v;
    }
};