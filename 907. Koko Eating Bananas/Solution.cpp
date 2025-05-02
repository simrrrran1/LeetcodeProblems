class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        long left = 1, right = piles[n-1];
        int res = piles[n-1];

        while(left <= right){
            long k = left + (right - left)/2;

            long hours = 0;
            for(int i: piles){
                hours += (i/k);
                if(i%k != 0) hours++;
            }

            if(hours <= h){
                if(res >= k){
                    res = k;
                }
                right = k - 1;
            }else{
                left = k + 1;
            }
        }
        return res;
    }
};

//[30,11,23,4,20], h = 6

//[30, 23, 20, 11, 4]