class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i:nums){
            s.insert(i);
        }
        int maxLen=0;
        for(int i:s){
            int x=i;
            if(s.find(x-1)==s.end()){
                int len=1;
                while(s.find(x+1)!=s.end()){
                    len++;
                    x++;
                }
                maxLen=max(maxLen,len);
            }
        }
        return maxLen;
    }
};