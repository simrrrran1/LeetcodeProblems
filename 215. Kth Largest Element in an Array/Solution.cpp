class Solution {
public:
    int helper(vector<int>& nums, int k, int left, int right){
        int pivot = nums[right];
        int p = left;

        for(int i=left; i<right; i++){
            if(nums[i] < pivot){
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[right], nums[p]);

        if(k < p){
           return helper(nums, k, left, p-1); 
        }
        else if(k > p){
            return helper(nums, k, p+1, right);
        }
        return nums[p];

        
    }
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, nums.size()-k, 0, nums.size()-1);
    }
};