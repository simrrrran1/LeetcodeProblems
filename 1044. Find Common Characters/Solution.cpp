class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        int n = words.size();

        vector<int> v(26, INT_MAX);

        for(int i=0; i<n; i++){
            vector<int> freq(26, 0);
            for(int j=0; j<words[i].size(); j++){
                freq[words[i][j]-'a']++;
            }

            for(int i=0; i<26; i++){
                v[i] = min(v[i], freq[i]);
            }
        }

        for(int i=0; i<26; i++){
            while(v[i]-- > 0){
                ans.push_back(string(1,i+'a'));
            }
        }

        return ans;
    }
};