class Solution {
public:
    long long numberOfWays(string s) {
        long long count0 = 0, count1 = 0;
        long long count01 = 0, count10 = 0;
        long long result = 0;

        for (char c : s) {
            if (c == '0') {
                count0++;
                result += count10;   // "101" pattern
            } else {
                count1++;
                result += count01;   // "010" pattern
            }

            if (c == '0') {
                count01 += count1;   // "01" pair
            } else {
                count10 += count0;   // "10" pair
            }
        }

        return result;
    }
};
