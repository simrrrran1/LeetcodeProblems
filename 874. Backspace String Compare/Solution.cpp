class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="";
        string s2="";
        for(char c:s){
            if(c=='#'){
                if(!s1.empty())
                s1.pop_back();
                continue;
            }
            s1.push_back(c);
        }
        for(char c:t){
            if(c=='#'){
                if(!s2.empty())
                s2.pop_back();
                continue;
            }
            s2.push_back(c);
        }
        return s1==s2;
    }
};