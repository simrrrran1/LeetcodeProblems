class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        
        // Step 1: Combine and sort all records by timestamp
        vector<tuple<int, string, string>> data;
        for (int i = 0; i < n; ++i) {
            data.push_back({timestamp[i], username[i], website[i]});
        }
        sort(data.begin(), data.end());

        // Step 2: Build a map of user -> list of websites visited in order
        unordered_map<string, vector<string>> userVisits;
        for (auto& [time, user, site] : data) {
            userVisits[user].push_back(site);
        }

        // Step 3: For each user, get all 3-sequences (no duplicates per user)
        map<vector<string>, set<string>> seqToUsers;
        for (auto& [user, sites] : userVisits) {
            int sz = sites.size();
            set<vector<string>> seen;  // Avoid duplicates per user
            for (int i = 0; i < sz; ++i) {
                for (int j = i + 1; j < sz; ++j) {
                    for (int k = j + 1; k < sz; ++k) {
                        vector<string> seq = {sites[i], sites[j], sites[k]};
                        if (seen.insert(seq).second) {
                            seqToUsers[seq].insert(user);
                        }
                    }
                }
            }
        }

        // Step 4: Find the most frequent 3-sequence
        int maxCount = 0;
        vector<string> result;
        for (auto& [seq, users] : seqToUsers) {
            if ((int)users.size() > maxCount || ((int)users.size() == maxCount && seq < result)) {
                maxCount = users.size();
                result = seq;
            }
        }

        return result;
    }
};
