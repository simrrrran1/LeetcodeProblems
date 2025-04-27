class Solution {
public:
    
    int calculate(string s) {
        int ans = 0;
        int prev = 0, curr = 0, i = 0;
        char currOp = '+';

        while(i < s.size()){
            if(isdigit(s[i])){
                while(i < s.size() && isdigit(s[i])){
                    curr = curr*10 + (s[i] - '0');
                    i++;
                }
                i--;

                if(currOp == '+'){
                    ans += curr;
                    prev = curr;
                }else if(currOp == '-'){
                    ans -= curr;
                    prev = -1*curr;
                }else if(currOp == '*'){
                    ans -= prev;
                    ans += (prev * curr);
                    prev *= curr;
                }else{
                    ans -= prev;
                    ans += (prev / curr);
                    prev /= curr;
                }
                curr = 0;
            }else if(s[i] != ' '){
                currOp = s[i];
            }
            i++;
        }


        return ans;
    }
};