class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        char c;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                s1.push(s[i]);
                continue;
            }
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(s1.empty()) return false;
                switch(s[i]){
                    
                    case '}':
                        c = s1.top();
                        if(c == '[' || c == '(') return false;
                        s1.pop();
                        break;

                    case  ']':
                        c = s1.top();
                        if(c == '{' || c == '(') return false;
                        s1.pop();
                        break;

                    case ')':
                        c = s1.top();
                        if(c == '[' || c == '{') return false;
                        s1.pop();
                        break;
                }
            }
        }

        return s1.empty();
    }
};