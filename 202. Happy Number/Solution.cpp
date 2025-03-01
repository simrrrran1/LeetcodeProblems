class Solution {
public:
    int sumOfSquares(int n){
        unordered_map<int,int>mp;
        mp[0] = 0;
        mp[1] = 1;
        mp[2] = 4;
        mp[3] = 9;
        mp[4] = 16;
        mp[5] = 25;
        mp[6] = 36;
        mp[7] = 49;
        mp[8] = 64;
        mp[9] = 81;
        int sum = 0;
        while(n){
            sum += mp[n%10];
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        if(n == 1)return true;
        while(n!=1 && s.find(n) == s.end()){
            s.insert(n);
            n = sumOfSquares(n);
            if(n == 1)return true;
        }
        return false;
    }
};