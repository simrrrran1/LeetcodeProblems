class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bp = -1;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                bp = i;
                break;
            }
        }

        for(int i=nums.size()-1; i>bp && bp!=-1; i--){
            if(nums[bp] < nums[i]){
                swap(nums[i], nums[bp]);
                break;
            }
        }

        reverse(nums.begin() + bp + 1, nums.end());   
    }
};