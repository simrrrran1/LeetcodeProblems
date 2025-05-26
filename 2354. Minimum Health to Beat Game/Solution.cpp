class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long sum = 1;
        int maxi = damage[0];
        for(int i=0; i<damage.size(); i++){
            sum += damage[i];
            maxi = max(maxi, damage[i]);
        }
        return sum - min(maxi, armor);
    }
};