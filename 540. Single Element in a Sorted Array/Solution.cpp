class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int left = 0, right = n-1;
        while(left <= right){
            int mid = left + ((right-left)/2);
            if((mid - 1 < 0 || nums[mid] != nums[mid-1]) && (mid + 1 == n || nums[mid] != nums[mid+1])){
                return nums[mid];
            }
            int leftLen = nums[mid-1] == nums[mid] ? mid-1 : mid;

            if(leftLen % 2 == 0){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
};