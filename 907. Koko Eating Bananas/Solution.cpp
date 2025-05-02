class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        long left = 1, right = piles[n-1];

        while(left <= right){
            long mid = left + (right - left)/2;

            long x = 0;
            for(int i: piles){
                x += (i/mid);
                if(i%mid != 0) x++;
            }
            if(x <= h){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};

//[30,11,23,4,20], h = 6

//[30, 23, 20, 11, 4]