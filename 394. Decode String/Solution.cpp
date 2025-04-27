class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> s1;
        for(int i=0; i<n; i++){
            if(s[i] == ']'){
                
                string temp = "";
                while(!s1.empty() && s1.top() != '['){
                    temp = s1.top() + temp;
                    s1.pop();
                }
                s1.pop();
                
                string num = "";
                while(!s1.empty() && isdigit(s1.top())){
                    num = s1.top() + num;
                    s1.pop();
                }
                int k = stoi(num);
                
                string x = "";
                while(k--){
                    x += temp;
                }
                
                for(int i=0; i<x.size(); i++){
                    s1.push(x[i]);
                }
                continue;
            }
            s1.push(s[i]);
        }
        string ans = "";

        while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};