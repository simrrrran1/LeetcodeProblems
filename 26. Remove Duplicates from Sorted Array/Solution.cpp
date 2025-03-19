class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1;

        while(right < nums.size()){
            if(nums[left] != nums[right]){
                left +=1;
                nums[left] = nums[right];
                
            }
            right++;
        }
        return left+1;
    }
};