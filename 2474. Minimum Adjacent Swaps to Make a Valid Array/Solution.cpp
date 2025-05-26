class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int largest = nums[0], smallest = nums[0], largest_idx = 0, smallest_idx = 0;

        for(int i=0; i<n; i++){
            if(largest <= nums[i]){
                largest = nums[i];
                largest_idx = i;
            }
            if(smallest > nums[i]){
                smallest = nums[i];
                smallest_idx = i;
            }
        }

        int dis = smallest_idx + (n-1-largest_idx);

        return smallest_idx > largest_idx ? dis-1 : dis;
    }
};