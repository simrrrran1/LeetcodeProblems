class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n;
        int i=0;
        int k=0;
        while(i<n){
            int cnt=1;
            while(i+1<n && nums[i+1]==nums[i]){
                cnt++;i++;
            }
            for(int j=0;j<min(cnt,2);j++){
                nums[k]=nums[i];k++;
            }i++;
        }
        return k;
    }
};