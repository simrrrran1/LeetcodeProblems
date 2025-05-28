class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
                if(s1.empty()) return false;
                else{
                    char c = s1.top();
                    s1.pop();
                    if(c == '('){
                        if(s[i] == '}' || s[i] == ']') return false;
                    }else if(c == '{'){
                        if(s[i] == ')' || s[i] == ']') return false;
                    }else if(c == '['){
                        if(s[i] == '}' || s[i] == ')') return false;
                    }
                }
            }else{
                s1.push(s[i]);
            }
        }
        return s1.empty();
    }
};