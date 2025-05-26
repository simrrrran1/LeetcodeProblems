class Solution {
public:
    long long numberOfWays(string s) {
        long long ans = 0;
        long long count_0 = 0, count_1 = 0, count_01 = 0, count_10 = 0;

        for(char c: s){
            if(c == '0'){
                count_0++;
                ans += count_10;
            }else{
                count_1++;
                ans += count_01;
            }

            if(c == '0'){
                count_01 += count_1;
            }else{
                count_10 += count_0;
            }
        }
        return ans;
    }
};