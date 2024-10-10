class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gSum=0,cSum=0;
        for(int i=0;i<n;i++){
            gSum+=gas[i];
            cSum+=cost[i];
        }
        if(gSum<cSum)return -1;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=(gas[i]-cost[i]);
            if(sum<0){
                sum=0;
                ans=i+1;
            }
        }
        return ans;
    }
};