class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string s = to_string(x);
        string s1 = s;
        reverse(s.begin(), s.end());
        return s1 == s;
    }
};