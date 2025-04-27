class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n == 0 || n == 1) return 0;

        int r = n-1;
        int res  = 0;

        while(r > 0 && arr[r-1] <= arr[r]) r -= 1;

        res = r;

        int l = 0;

        while(l < r){

            while(r < n && arr[l] > arr[r]) r += 1;

            res = min(res, r-l-1);
            
            if(arr[l] > arr[l+1]) break;
            l += 1;
        }

        return res;

    }
};