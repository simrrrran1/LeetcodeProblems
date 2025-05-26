class Solution {
public:
    int minimumKeypresses(string s) {
        int n = s.size();
        vector<int> v(26, 0);
        for(char c: s){
            v[c - 'a']++;
        }
        sort(v.begin(), v.end(), greater<int>());

        int ans = 0, count = 0;

        for(int i=0; i<26; i++){
            if(i % 9 == 0) count += 1;
            ans += (count * v[i]);
        }

        return ans;

        
    }
};

//abcdefghijkl

//apple
//abcdefghi
