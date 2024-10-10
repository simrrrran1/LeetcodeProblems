class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            string s=haystack.substr(i,needle.size());
            if(s==needle)return i;
        }
        return -1;
    }
};