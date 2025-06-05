class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        
        // Keep placing each number at its correct index until a duplicate is found
        while(nums[i] != nums[nums[i]]) {
            // Swap nums[i] with the number at its target index nums[nums[i]]
            swap(nums[i], nums[nums[i]]);
        }

        // At this point, nums[i] == nums[nums[i]], which means it's a duplicate
        return nums[i];
    }
};
