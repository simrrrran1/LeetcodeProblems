class Solution {
public:
    bool isDigit(char s){
        if(s=='0'||s=='1'||s=='2'||s=='3'||s=='4'||s=='5'||s=='6'||s=='7'||s=='8'||s=='9')return true;
        return false;
    }
    string decodeString(string s) {
        stack<char>s1;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string s2="";
                while(s1.top()!='['){
                    s2=s1.top()+s2;
                    s1.pop();
                }
                s1.pop();
                string k="";
                while(!s1.empty() && isDigit(s1.top())){
                    k=s1.top()+k;
                    s1.pop();
                }
                int x=stoi(k);
                string temp=s2;
                for(int i=0;i<x-1;i++){
                    s2+=temp;
                }
                for(int i=0;i<s2.size();i++)
                s1.push(s2[i]);
            }else{
                s1.push(s[i]);
            }
        }
        string ans="";
        while(!s1.empty()){
            ans+=s1.top();
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};