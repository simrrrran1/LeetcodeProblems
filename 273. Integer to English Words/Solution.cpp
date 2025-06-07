class Solution {
public:
    // Mapping numbers from 0 to 19 to their English words
    unordered_map<int, string> ones = {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
        {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
        {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"},
        {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
        {18, "Eighteen"}, {19, "Nineteen"}
    };

    // Mapping for multiples of ten from 20 to 90
    unordered_map<int, string> tens = {
        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
        {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
    };

    // Thousand powers from least significant to most
    vector<string> bigNos = {"", "Thousand", "Million", "Billion"};

    // Converts a number less than 1000 into English words
    string getString(int n) {
        vector<string> res;

        int hundreds = n / 100;
        if (hundreds != 0) {
            res.push_back(ones[hundreds] + " Hundred");
        }

        int last_digits = n % 100;
        if (last_digits >= 20) {
            int ten_place = (last_digits / 10) * 10;
            int ones_place = last_digits % 10;
            res.push_back(tens[ten_place]);
            if (ones_place != 0) {
                res.push_back(ones[ones_place]);
            }
        } else if (last_digits > 0) {
            res.push_back(ones[last_digits]);
        }

        string s;
        for (string &word : res) {
            s += word + " ";
        }

        // Remove trailing space
        if (!s.empty() && s.back() == ' ') s.pop_back();
        return s;
    }

    // Main function to convert entire number
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        vector<string> ans;
        int i = 0;

        while (num > 0) {
            int digits = num % 1000;
            if (digits != 0) {
                string chunk = getString(digits);
                if (!bigNos[i].empty()) {
                    chunk += " " + bigNos[i];
                }
                ans.push_back(chunk);
            }
            num /= 1000;
            i++;
        }

        reverse(ans.begin(), ans.end());

        string result;
        for (int j = 0; j < ans.size(); j++) {
            result += ans[j];
            if (j != ans.size() - 1) result += " ";
        }

        return result;
    }
};
