class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = 0;
        while(right < nums.size()){
            if(nums[right] != val){
                swap(nums[left], nums[right]); left++;
            }
            right++;
        }
        return left;
    }
};