class Solution {
public:
    // Helper function to perform DFS and detect cycles
    bool dfs(vector<vector<int>>& adj, int start, vector<bool>& vis, unordered_set<int>& s) {
        vis[start] = true;   // Mark the current node as visited (global)
        s.insert(start);     // Add to recursion stack (used for cycle detection)

        for (auto& i : adj[start]) {
            if (!vis[i]) {
                // If neighbor not visited, recurse
                if (!dfs(adj, i, vis, s))
                    return false;
            } else if (s.count(i)) {
                // If neighbor is already in recursion stack -> cycle detected
                return false;
            }
        }

        // Backtrack: remove from recursion stack
        s.erase(start);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // Adjacency list

        // Build graph: edge from course B -> A means A depends on B
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> vis(numCourses, false); // To track visited nodes globally

        // Run DFS for each course
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                unordered_set<int> s; // Recursion stack to detect cycle
                if (!dfs(adj, i, vis, s))
                    return false; // If cycle is detected, cannot finish all courses
            }
        }

        return true; // No cycle detected, all courses can be finished
    }
};
