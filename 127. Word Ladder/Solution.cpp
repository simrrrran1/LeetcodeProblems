class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Step 1: Store all words from the wordList in a map for O(1) lookup
        unordered_map<string, int> mp;
        for(string s : wordList){
            mp[s]++;
        }

        // Step 2: If the endWord is not in wordList, transformation is not possible
        if(mp.find(endWord) == mp.end()) return 0;

        // Step 3: Build an adjacency map using pattern matching
        // Each word can generate M generic states (replace one char with '*')
        unordered_map<string, vector<string>> mp1;
        wordList.push_back(beginWord); // Make sure beginWord is included for pattern linking

        for(string word : wordList){
            for(int i = 0; i < word.size(); i++){
                // Create a pattern with '*' replacing one letter
                string pattern = word.substr(0, i) + "*" + word.substr(i + 1);
                mp1[pattern].push_back(word);  // Group all words matching the pattern
            }
        }

        // Step 4: Set to track visited words and avoid revisiting in BFS
        unordered_set<string> visited;
        visited.insert(beginWord);

        // Step 5: Standard BFS initialization
        queue<string> q;
        q.push(beginWord);
        int ans = 1;  // Ladder length starts at 1 (includes beginWord)

        // Step 6: BFS traversal
        while(!q.empty()){
            int levelSize = q.size();  // Number of nodes at current level

            for(int i = 0; i < levelSize; i++){
                string currentWord = q.front();
                q.pop();

                // If we reach the endWord, return the number of steps taken
                if(currentWord == endWord) return ans;

                // Try all possible generic transformations of currentWord
                for(int j = 0; j < currentWord.size(); j++){
                    string pattern = currentWord.substr(0, j) + "*" + currentWord.substr(j + 1);

                    // For each matching pattern, get all connected words (neighbors)
                    for(auto& neighbor : mp1[pattern]){
                        // If this neighbor hasn't been visited yet, add it to BFS queue
                        if(visited.find(neighbor) == visited.end()){
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }

            // Increment ladder length after processing current BFS level
            ans += 1;
        }

        // Step 7: If no path found from beginWord to endWord
        return 0;
    }
};
