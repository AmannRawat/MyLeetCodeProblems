//Brute Force Approach using BFS Not For Leetcode
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 1. Create a set for fast O(1) lookups
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // 2. Queue stores the entire PATH (sequence of words)
        queue<vector<string>> q;
        q.push({beginWord});
        
        // 3. To store the final answers
        vector<vector<string>> ans;
        
        // 4. Tracks words used in the CURRENT level to delete them later
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        
        int level = 0;
        
        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            
            // OPTIMIZATION: Erase words used in the PREVIOUS level
            // We only erase when the path length increases (meaning we moved to a new level)
            if (vec.size() > level) {
                level++;
                for (auto it : usedOnLevel) {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            
            string word = vec.back(); // Get the last word in the current path
            
            // CHECK: If we reached the target word
            if (word == endWord) {
                // If it's the first time we found it, simply add it.
                if (ans.empty()) {
                    ans.push_back(vec);
                } 
                // If we found another path of the SAME shortest length, add it.
                else if (ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }
            
            // TRANSFORMATION: Try changing every character 'a' to 'z'
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    
                    // If the new word exists in the set
                    if (st.count(word) > 0) {
                        // Create a new path with this word added
                        vec.push_back(word);
                        q.push(vec);
                        
                        // Mark this word as visited for this level
                        usedOnLevel.push_back(word);
                        
                        // Backtrack: Remove the word to try other possibilities for this position
                        vec.pop_back();
                    }
                }
                word[i] = original; // Restore the original character
            }
        }
        return ans;
    }
};

//Optimized Approach
class Solution {
    // Global variables to be used in DFS
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string bWord;

private:
    void dfs(string word, vector<string>& seq) {
        // Base Case: If we reach the beginWord
        if (word == bWord) {
            // Since we are backtracking from end to start, the sequence is reversed.
            // We need to reverse it to get [beginWord -> ... -> endWord]
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            // Reverse back to maintain the sequence for other recursion branches (backtracking)
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mpp[word];
        int sz = word.size();

        // Try changing every character to find the parent node (previous step)
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                
                // Key Optimization Check:
                // 1. The word must exist in our map (visited in BFS)
                // 2. The level must be exactly (current_level - 1)
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); // Backtrack
                }
            }
            word[i] = original; // Restore character
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Clear global variables for fresh run
        mpp.clear();
        ans.clear();
        bWord = beginWord;

        // Create a set for O(1) lookups of the wordList
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // Step 1: BFS to map the shortest levels
        queue<string> q;
        q.push(beginWord);
        mpp[beginWord] = 1; // Level 1 for beginWord
        st.erase(beginWord);
        
        int sz = beginWord.size();

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            
            int steps = mpp[word];
            
            // Optimization: If we already found the endWord at this level, 
            // we don't need to explore further depths in BFS, just finish this level map.
            if (word == endWord) break; 

            for (int i = 0; i < sz; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word); // Remove to prevent cycles/redundant processing
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        // Check if endWord was reached. If not, return empty.
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq); // Step 2: DFS from End to Begin
        }
        
        return ans;
    }
};