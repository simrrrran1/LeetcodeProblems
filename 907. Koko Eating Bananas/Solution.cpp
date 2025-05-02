class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        long left = 1, right = *max_element(piles.begin(), piles.end());
        int res = right;

        while(left <= right){
            long k = left + (right - left)/2;

            long hoursTaken = 0;

            for(int i: piles){
                hoursTaken += (i/k);
                if(i%k != 0) hoursTaken++;
            }

            if(hoursTaken <= h){
                if(res >= k){
                    res = k;
                }
                right = k-1;
            }else{
                left = k+1;
            }

        }
        return res;
    }
};