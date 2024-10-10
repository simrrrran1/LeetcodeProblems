class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1;
        string s="";
        int carry=0;
        while(i!=-1 || j!=-1 || carry){
            if(i!=-1){
                carry+=(a[i]-'0');
                i--;
            }
            if(j!=-1){
                carry+=(b[j]-'0');
                j--;
            }
            char c=(carry%2)+'0';
            s.push_back(c);
            carry/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};