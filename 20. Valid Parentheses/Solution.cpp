class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n==0)return false;
        stack<char>s1;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                s1.push(c);
                continue;
            }else if(c=='}'||c==']'||c==')'){
                if(s1.empty())return false;
                switch(c){
                    case ')':{
                        char a=s1.top();
                        s1.pop();
                        if(a=='{'||a=='[')return false;
                        break;
                    }
                    case '}':{
                        char a=s1.top();
                        s1.pop();
                        if(a=='('||a=='[')return false;
                        break;
                    }
                    case ']':{
                        char a=s1.top();
                        s1.pop();
                        if(a=='('||a=='{')return false;
                        break;
                    }
                }
            }
        }
        return s1.empty();  
    }
};