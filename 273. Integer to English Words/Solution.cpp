class Solution {
public:
    // Main function to convert number to words
    string numberToWords(int num) {
        if (num == 0) return "Zero";  // Edge case: zero

        // Suffixes for every group of 3 digits (starting from thousand)
        string bigString[] = {"Thousand", "Million", "Billion"};
        
        string result = numberToWordsHelper(num % 1000); // Process the last 3 digits
        num /= 1000;

        // Process each group of 3 digits and append appropriate suffix
        for (int i = 0; i < 3; ++i) {
            if (num % 1000 > 0) {
                // Prepend current group (converted to words) and its corresponding unit
                result = numberToWordsHelper(num % 1000) + bigString[i] + " " + result;
            }
            num /= 1000;
        }

        // Remove any trailing space at the end and return result
        return result.empty() ? result : result.substr(0, result.size() - 1);
    }

    // Helper function to convert numbers from 1 to 999 into words
    string numberToWordsHelper(int num) {
        // Maps for digits, teens, and tens
        string digitString[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string teenString[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
                               "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tenString[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", 
                              "Sixty", "Seventy", "Eighty", "Ninety"};

        string result = "";

        // Process hundreds place
        if (num >= 100) {
            result += digitString[num / 100] + " Hundred ";
        }
        num %= 100;

        // Process teens (10 to 19)
        if (num >= 10 && num < 20) {
            result += teenString[num - 10] + " ";
        } 
        else {
            // Process tens place (20, 30, ..., 90)
            if (num >= 20) {
                result += tenString[num / 10] + " ";
            }

            // Process units place (1 to 9)
            num %= 10;
            if (num > 0) {
                result += digitString[num] + " ";
            }
        }

        return result;
    }
};
