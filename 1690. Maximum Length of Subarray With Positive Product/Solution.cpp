class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for(int i=0;i<n;){
            int s = i; //s is the starting index of subarray
            int c = 0; //c will keep count of no of negative numbers
            
            //ignore zeroes in starting of the array
            while(s<n and nums[s] == 0) s++;
            
            int e = s; //e will be used to traverse the subarray
            int sn = -1; //index of 1st negative no
            int ln = -1; //index of last negative no
            
            while(e<n and nums[e] != 0){
                
				//when we encounter a negative no we increament c
                if(nums[e] < 0){
                    c++;
                    if(sn == -1) sn = e;  //first negative number
                    ln = e;
                }
                
                e++;
            }
            
            //now e(end) will either point to 0 or n
            
            //if no of negatives in subarray are even
            if(c%2 == 0){
                ans = max(ans, e-s);
            }
            else{
                
                //remove first negative no
                if(sn != -1){
                    ans = max(ans , e-sn-1);
                }
				
                 //OR  
                //remove last negative no
                if(ln != -1){
                    ans = max(ans , ln-s);
                }
            }
            
            i = e; //now i will point to the index next to the last element of the current subarray
        }
        return ans;
    }
};