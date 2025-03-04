class Solution {
public:
    bool helper(int mid, vector<int>&candies, long long k){
        long long ans = 0;

        for(int i:candies){
            ans += (i/mid);
        }
        return ans >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        //if(k > candies.size()) return 0;
        int low = 1, high = *max_element(candies.begin(), candies.end()), res = 0;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(helper(mid, candies, k)){
                res = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }
};