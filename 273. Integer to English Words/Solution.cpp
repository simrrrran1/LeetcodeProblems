class Solution {
public:
    // Maps numbers from 0 to 19 to their English words
    unordered_map<int, string> ones = {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
        {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
        {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"},
        {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
        {18, "Eighteen"}, {19, "Nineteen"}
    };

    // Maps tens multiples (20, 30, ..., 90) to their English words
    unordered_map<int, string> tens = {
        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
        {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
    };

    // Labels for thousand powers (used while converting each group of 3 digits)
    vector<string> bigNos = {"", "Thousand", "Million", "Billion"};

    // Converts a number < 1000 into English words
    string getString(int n) {
        vector<string> res;

        // Handle hundreds place
        int hundreds = n / 100;
        if (hundreds != 0) {
            res.push_back(ones[hundreds] + " Hundred");  // e.g., 300 -> "Three Hundred"
        }

        // Handle tens and ones
        int last_digits = n % 100;
        if (last_digits >= 20) {
            int ten_place = (last_digits / 10) * 10;  // Round down to nearest 10
            int ones_place = last_digits % 10;
            res.push_back(tens[ten_place]);           // e.g., 70 -> "Seventy"
            if (ones_place != 0) {
                res.push_back(ones[ones_place]);      // e.g., 3 -> "Three"
            }
        } else if (last_digits > 0) {
            // Handle numbers from 1 to 19 directly
            res.push_back(ones[last_digits]);         // e.g., 13 -> "Thirteen"
        }

        // Combine all parts into a single string with spaces
        string s;
        for (string &word : res) {
            s += word + " ";
        }

        // Trim trailing space
        if (!s.empty() && s.back() == ' ') s.pop_back();
        return s;
    }

    // Converts entire number into English words
    string numberToWords(int num) {
        // Edge case: if number is zero
        if (num == 0) return "Zero";

        vector<string> ans; // Store parts of the English words
        int i = 0;          // Index to track "Thousand", "Million", etc.

        // Process 3-digit chunks from right to left (e.g., 1,234,567 -> 567, 234, 1)
        while (num > 0) {
            int digits = num % 1000; // Extract last 3 digits
            if (digits != 0) {
                string chunk = getString(digits); // Convert chunk to English
                if (!bigNos[i].empty()) {
                    chunk += " " + bigNos[i];     // Append scale word (e.g., "Million")
                }
                ans.push_back(chunk);             // Add to result list
            }
            num /= 1000;  // Move to next 3-digit chunk
            i++;
        }

        // Since we processed from least significant group, reverse for correct order
        reverse(ans.begin(), ans.end());

        // Join all chunks into one string with proper spaces
        string result;
        for (int j = 0; j < ans.size(); j++) {
            result += ans[j];
            if (j != ans.size() - 1) result += " ";
        }

        return result;
    }
};
