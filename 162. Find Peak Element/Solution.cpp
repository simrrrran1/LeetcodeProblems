class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // If there's only one element, it is the peak by default
        if (nums.size() == 1) return 0;

        int left = 0, right = nums.size() - 1;

        // Binary search loop
        while (left <= right) {
            int mid = left + ((right - left) / 2);

            // Case 1: If the mid element is less than its left neighbor,
            // then the peak must be on the left side
            if (mid > 0 && nums[mid - 1] > nums[mid]) {
                right = mid - 1;
            }
            // Case 2: If the mid element is less than its right neighbor,
            // then the peak must be on the right side
            else if (mid < nums.size() - 1 && nums[mid + 1] > nums[mid]) {
                left = mid + 1;
            }
            // Case 3: If mid is greater than both neighbors or at the edge, it's a peak
            else {
                return mid;
            }
        }

        // This line should theoretically never be reached
        return -1;
    }
};
