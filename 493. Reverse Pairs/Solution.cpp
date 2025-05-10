class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        int i = low, j = mid+1;
        int k = 0;
        vector<int> v(high-low+1, 0);

        while(i <= mid && j<= high){
            if(nums[i] <= nums[j]){
                v[k] = nums[i];
                i++;
            }else{
                v[k] = nums[j];
                j++;
            }
            k++;
        }
        while(i<=mid){
            v[k++] = nums[i++]; 
        }
        while(j<=high){
            v[k++] = nums[j++]; 
        }
        k = 0;
        for(int i=low; i<=high; i++){
            nums[i] = v[k];
            k++;
        }

    }
    int countPairs(vector<int>& nums, int low, int mid, int high){
        int right = mid+1;
        int cnt = 0;

        for(int i=low; i<=mid; i++){
            while(right <= high && nums[i] > 2LL*nums[right]){
                right++;
            }
            cnt += (right - (mid+1));
        }
        return cnt;

    }
    int mergeSort(vector<int>& nums, int low, int high){
        int res = 0;
        if(low >= high) return 0;
        int mid = low + (high-low)/2;
        res += mergeSort(nums, low, mid);
        res += mergeSort(nums, mid+1, high);
        res += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return res;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};