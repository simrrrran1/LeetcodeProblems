class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int i = 0, j = 0;
        int s1 = encoded1.size();
        int s2 = encoded2.size();

        vector<vector<int>> v;
        
        while(i < s1 && j < s2){
            int val1 = encoded1[i][0];
            int freq1 = encoded1[i][1];
            int val2 = encoded2[j][0];
            int freq2 = encoded2[j][1];

            int val = val1 * val2;
            int freq = min(freq1, freq2);
            
            if(v.empty() || v.back()[0] != val){
                v.push_back({val, freq});
            }else{
                v.back()[1] += freq;
            }

            encoded1[i][1] -= freq;
            encoded2[j][1] -= freq;
            
            if(encoded1[i][1] == 0){
                i++;
            }
            if(encoded2[j][1] == 0){
                j++;
            }
        }
        return v;
    }
};