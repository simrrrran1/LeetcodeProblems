class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string curr = "";

        for (char c : path) {
            if (c == '/') {
                if (curr == "..") {
                    if (!s.empty()) {
                        s.pop();  // Go back to the previous directory, if possible
                    }
                } else if (curr != "" && curr != ".") {
                    s.push(curr);  // Push the valid directory name onto the stack
                }
                curr = "";  // Reset the current directory name
            } else {
                curr += c;  // Accumulate characters for the current directory name
            }
        }

        // Handle the last segment after the loop
        if (curr == "..") {
            if (!s.empty()) {
                s.pop();
            }
        } else if (curr != "" && curr != ".") {
            s.push(curr);
        }

        string ans = "";
        while (!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }

        // If the stack is empty, return "/" (root directory)
        return ans.empty() ? "/" : ans;
    }
};
