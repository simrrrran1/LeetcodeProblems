class Solution {
public:
    int hammingWeight(int n) {
        vector<int> b(32,0);
        int cnt = 0;

        for(int i=31; i>=0; i--){
            b[i] = n%2;
            if(b[i] == 1) cnt++;
            n /= 2;
        }

        return cnt;
    }
};