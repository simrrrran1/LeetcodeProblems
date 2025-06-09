class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // Separate vectors for letter-logs and digit-logs
        vector<string> letterLog;
        vector<string> digitLog;
        vector<string> ans; // Final answer to store reordered logs

        // Step 1: Classify logs into letter-logs and digit-logs
        for(int i = 0; i < logs.size(); i++) {
            // Find the index of the first character after the identifier
            int idx = logs[i].find(" ") + 1;

            // Check if the log is a digit-log (first character after identifier is a digit)
            if(logs[i][idx] >= '0' && logs[i][idx] <= '9') {
                digitLog.push_back(logs[i]); // Store digit-log separately
            } else {
                letterLog.push_back(logs[i]); // Store letter-log separately
            }
        }

        // Step 2: Sort the letter-logs with custom comparator
        sort(letterLog.begin(), letterLog.end(), [](string& a, string& b) {
            // Find the start of the log content (after identifier)
            int aIdx = a.find(" ") + 1;
            int bIdx = b.find(" ") + 1;

            // Extract the content part of both logs (excluding identifier)
            string contentA = a.substr(aIdx);
            string contentB = b.substr(bIdx);

            // If content is the same, sort lexicographically by identifier
            if(contentA == contentB) {
                return a < b; // a < b does lexicographical comparison of entire strings
            }

            // Otherwise, sort lexicographically by content
            return contentA < contentB;
        });

        // Step 3: Combine sorted letter-logs followed by original-order digit-logs
        for(int i = 0; i < letterLog.size(); i++) {
            ans.push_back(letterLog[i]); // Append letter logs first
        }

        for(int i = 0; i < digitLog.size(); i++) {
            ans.push_back(digitLog[i]); // Then append digit logs in original order
        }

        return ans; // Return the reordered logs
    }
};
