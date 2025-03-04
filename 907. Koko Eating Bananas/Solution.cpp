class Solution {
public:
    long helper(int k, vector<int>&piles){
        long hours = 0;
        for(int i:piles){
            hours += ((i+k-1)/k);
        }
        return hours;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        long k = 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            k = helper(mid, piles);
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