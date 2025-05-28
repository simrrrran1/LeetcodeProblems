class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while(nums[i] != nums[nums[i]]){
            swap(nums[i], nums[nums[i]]);
        }
        return nums[i];
    }
};


// 001 010 011 100 101 
// 011 011 011 011 011
// 010 001 000 111 110