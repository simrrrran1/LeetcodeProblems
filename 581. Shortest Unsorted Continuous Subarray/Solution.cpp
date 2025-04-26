class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return 0;

        int start = 0, end = -1, min = nums[n-1], max = nums[0];

        for(int i=1; i<n; i++){
            if(max > nums[i]){
                end = i;
            }else{
                max = nums[i];
            }
        }

        for(int i=n-2; i>=0; i--){
            if(min < nums[i]){
                start = i;
            }else{
                min = nums[i];
            }
        }

        return end - start + 1;
        // while(start+1 < n && nums[start] == nums[start+1]) start++;
        // while(end-1 >= 0 && nums[end] == nums[end-1]) end--;
        

        // return (end == start) ? 0 : end - start + 1;

    }
};