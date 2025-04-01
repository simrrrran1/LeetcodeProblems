class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;

        for(int i=1; i<n-1; i++){
            int left = 0, right = 0;

            for(int j=0; j<i; j++){
                if(rating[j] < rating[i])left++;
            }
            
            for(int j=i+1; j<n; j++){
                if(rating[j] > rating[i])right++;
            }

            ans += (left*right);

            int left_larger = i - left;
            int right_smaller = n - i - 1 - right;

            ans += (left_larger * right_smaller);
        }

        return ans;
    }
};