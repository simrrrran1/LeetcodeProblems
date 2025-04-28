class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        int len = 0;

        for(int i = 0; i < n; i++) {
            int left = i, right = i;
            // Odd length palindrome
            while(left >= 0 && right < n && s[left] == s[right]) {
                if((right - left + 1) > len) {
                    res = s.substr(left, right - left + 1);
                    len = right - left + 1;
                }
                left--;
                right++;
            }

            left = i;
            right = i + 1;
            // Even length palindrome
            while(left >= 0 && right < n && s[left] == s[right]) {
                if((right - left + 1) > len) {
                    res = s.substr(left, right - left + 1);
                    len = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return res;
    }
};
