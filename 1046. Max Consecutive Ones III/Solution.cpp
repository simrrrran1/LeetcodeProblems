class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_ones = 0;

        int start = 0, end = 0;

        while(end < nums.size()){
            if(nums[end] == 0){
                k -= 1;
            }
            while(k < 0){
                if(nums[start] == 0) k += 1;
                start += 1;
            }

            max_ones = max(max_ones, end-start+1);
            end += 1;
        }
        return max_ones;
    }
};