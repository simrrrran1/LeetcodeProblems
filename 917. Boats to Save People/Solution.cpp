class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int ans = 0;

        int i=0, j=n-1;

        while(i <= j){
            int sum = people[i] + people[j];
            if(sum <= limit){
                ans++;
                i++;j--;
            }else if(sum > limit){
                ans++;
                j--;
            }
        }
        return ans;
    }
};