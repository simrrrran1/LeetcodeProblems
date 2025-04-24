class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> s1;
        string ans = "";

        for(int i=0; i<s.size(); i++){
            if(!s1.empty() && s1.top().first == s[i]){
                pair<char, int> p = s1.top();
                s1.pop();
                p.first = s[i];
                p.second += 1;
                s1.push(p);
                if(p.second == k){
                    s1.pop();
                    continue;
                }
            }else{
                s1.push({s[i], 1});
            }
        }
        while(!s1.empty()){
            pair<char,int> p = s1.top();
            while(p.second--){
                ans += p.first;
            }
            s1.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};