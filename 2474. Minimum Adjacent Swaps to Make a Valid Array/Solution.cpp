class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int largest = nums[0], smallest = nums[0], smallest_idx = 0, largest_idx = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] < smallest){
                smallest = nums[i];
                smallest_idx = i;
            }
            if(nums[i] >= largest){
                largest = nums[i];
                largest_idx = i;
            }
        }

        int swaps = smallest_idx + (n - 1 - largest_idx);
        return smallest_idx > largest_idx ? swaps - 1 : swaps; 
    }
};