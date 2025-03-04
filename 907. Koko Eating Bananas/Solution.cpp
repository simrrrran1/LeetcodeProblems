class Solution {
public:
    long helper(int k, vector<int>&piles){
        long hours = 0;
        for(int i:piles){
            hours += ceil((double)i/(double)k);
            //if(i%k != 0) hours++;
        }
        return hours;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            long k = helper(mid, piles);
            if(k <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }


    /*
    piles = [30,11,23,4,20]
    
    [4, 11, 20, 23, 30] -> 88

    1 - 88

    44 

    h = 5
    
    */
};