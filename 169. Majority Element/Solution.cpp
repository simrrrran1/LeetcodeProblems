class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int v = 0;
        int count = 0;

        for(int i: nums){
            if(count == 0){
                v = i;
            }
            if(i == v){
                count++;
            }else if(i != v){
                count--;
            }
            if(count < 0) count = 0;
        }
        return v;

    }
};