class Solution {
public:

    bool isDigit(char s){
        if(s=='0'||s=='1'||s=='2'||s=='3'||s=='4'||s=='5'||s=='6'||s=='7'||s=='8'||s=='9')return true;
        return false;
    }

    string decodeString(string s) {
        string ans = "";
        stack<char> s1;

        for(int i=0; i<s.size(); i++){

            if(s[i]!=']'){
                s1.push(s[i]);
            }
            else{

                //decode curr string
                string curr = "";
                while(!s1.empty() &&  s1.top()!='[' ){
                    curr = s1.top() + curr;
                    s1.pop();
                }

                s1.pop(); //remove [


                //decode the number of repetitions
                string num = "";
                while(!s1.empty() && isDigit(s1.top()) ){
                    num = s1.top() + num;
                    s1.pop();
                }

                //convert string to number k
                int k = stoi(num);
                // int k = 0;
                // for(int i=0; i<num.size(); i++){
                //     k = (k * 10) + (num[i] - '0');
                // }

                //copy temp to curr
                string temp = curr;
                for(int i=0; i<k-1; i++){
                    curr += temp;
                }

                //push curr to stack
                for(int i=0; i<curr.size(); i++){
                    s1.push(curr[i]);
                }

            }


        }

        while(!s1.empty()){
            ans+=s1.top();
            s1.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};