class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> charCount;

        for (int i = 0; i < s.length(); i++) {
            char chr = s[i];
            charCount[chr]++; // counts the frequency of each character
        }

        int maxFreq = 0;  //intialise max freq to 0
        char maxChar = '\0';  //intialise an empty character
                             

        for (const auto& pair : charCount) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second; // to find the maximum frequency
                maxChar = pair.first;  //gives character having maximum frequency
            }
        }

        int indx = 0; //start filling ; initialise a starting index

        while (maxFreq > 0 && indx < s.length()) {  // Step 1: Place the max frequency character at even indices
                                    
            s[indx] = maxChar;
            maxFreq--; //reduce it frequency
            indx += 2;  //even index
        }

        if (maxFreq !=0) {   // if we cant place first character of maximum frequency correctly then we cant arrange all other properly
            return ""; //therefore return empty string
        }

        // Step 2: Place the rest of the characters
        for (const auto& pair : charCount) {
            char c = pair.first;
            int count = pair.second;

            if (c == maxChar) continue;

            while (count > 0) {
                {
                    if (indx >= s.length()) // if indices are full 
                        indx = 1;  // start filling at odd indices if even 
                }

                s[indx] = c;
                count--;
                indx += 2;
            }
        }
        return s;
    }
};

// T.C = O(N)
// s.c = O(1)