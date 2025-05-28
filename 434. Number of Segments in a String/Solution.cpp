class Solution {
public:
    int countSegments(string s) {
        if(s == "") return 0;
        int i = 0;
        while(i<s.size() && s[i] == ' '){
            i++;
        }
        vector<string> v;
        for(; i<s.size();){
            string s1 = "";
            while(i<s.size() && s[i] != ' '){
                s1 += s[i];
                i++;
            }
            while(i<s.size() && s[i] == ' '){
                i++;
            }
            v.push_back(s1);
        }
        return v.size();
    }
};