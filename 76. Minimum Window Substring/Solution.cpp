class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "" || s == "") return "";

        unordered_map<char, int> tMap, sMap;

        for (char c : t) {
            tMap[c]++;
        }

        int have = 0, need = tMap.size();
        int left = 0, resLen = INT_MAX;
        int resStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            sMap[c]++;

            if (tMap.count(c) && sMap[c] == tMap[c]) {
                have++;
            }

            while (have == need) {
                // Update result
                if (right - left + 1 < resLen) {
                    resLen = right - left + 1;
                    resStart = left;
                }

                // Contract from the left
                sMap[s[left]]--;
                if (tMap.count(s[left]) && sMap[s[left]] < tMap[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
    }
};
