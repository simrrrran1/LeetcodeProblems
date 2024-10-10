class Solution {
public:
    bool isalphanum(char c){
        return ((c>='A' && c<='Z')||(c>='a' && c<='z') || (c>='0' && c<='9'));
    }
    bool isPalindrome(string s) {
        if(s.empty()==true)return true;
        int i=0, j=s.size()-1;
        while(i<=j){
            if(isalphanum(s[i])==false){
                i++;continue;
            }if(isalphanum(s[j])==false){
                j--;continue;
            }
            if(tolower(s[i])!=tolower(s[j]))return false;
            i++;j--;
        }
        return true;

    }
};