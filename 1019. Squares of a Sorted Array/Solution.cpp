class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        vector<int> ans;
        while(left<=right){
            int x=abs(nums[left]);
            int y=abs(nums[right]);
            if(x<y){
                ans.push_back(y*y);right--;
            }else{ 
                ans.push_back(x*x);left++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // vector<int> v(10001,0);
        // for(int i=0;i<n;i++){
        //     int x=abs(nums[i]);
        //     v[x]++;
        // }
        // vector<int> ans;
        // for(int i=0;i<=1000;i++){
        //     while(v[i]!=0){
        //         ans.push_back(i*i);
        //         v[i]--;
        //     }
        // }
        // return ans;
    }
};