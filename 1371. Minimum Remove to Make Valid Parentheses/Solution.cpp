class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int cnt = 0;
        vector<char> v;

        for(int i=0; i<s.size(); i++){
            if(s[i] == ')' && cnt==0) continue;
            if(s[i] == '(')cnt++;
            if(s[i] == ')')cnt--;
            v.push_back(s[i]);
        }

        for(int i=v.size()-1; i>=0; i--){
            if(v[i] == '(' && cnt > 0)cnt--;
            else ans.push_back(v[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};