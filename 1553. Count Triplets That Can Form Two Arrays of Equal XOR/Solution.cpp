class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int> prefix(n+1,0);
        int ans=0;
        unordered_map<int,int> count,sum;
        sum[0]=0;
        count[0]=1;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]^arr[i-1];
            int x=prefix[i];
            ans+=(i-1)*count[x]-sum[x];
            sum[x]+=i;
            count[x]+=1;
        }
        return ans;
    }
};