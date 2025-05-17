class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v;
        while(num){
            v.push_back(num % 10);
            num /= 10;
        }
        reverse(v.begin(), v.end());

        int max_digit = 0, max_idx = -1, swap_i = -1, swap_j = -1;

        for(int i=v.size()-1; i>=0; i--){
            if(v[i] > max_digit){
                max_digit = v[i];
                max_idx = i;
            }
            else if(v[i] < max_digit){
                swap_i = i;
                swap_j = max_idx;
            }
        }

        if(swap_i != -1 && swap_j != -1) swap(v[swap_i], v[swap_j]);

        int ans = 0;
        for(int i=0; i<v.size(); i++){
            ans = ans*10 + v[i];
        }
        return ans;
    }
};

