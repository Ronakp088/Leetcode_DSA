class Solution {
public:
    unordered_map<string, int> mpp;
    string b;
    vector<vector<string>> ans;

    void dfs(string word, vector<string>& vec) {
        if(word == b) {
            reverse(vec.begin(), vec.end());
            ans.push_back(vec);
            reverse(vec.begin(), vec.end());
            return;
        }
        int steps = mpp[word];
        for(int i = 0; i < word.size(); i++) {
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if(mpp.count(word) && mpp[word] + 1 == steps) {
                    vec.push_back(word);
                    dfs(word, vec);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);
        while(!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mpp[word];
            if(word == endWord) break;
            for(int i = 0; i < word.size(); i++) {
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(st.count(word) > 0) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if(mpp.count(endWord)) {
            vector<string> vec = {endWord};
            dfs(endWord, vec);
        }
        return ans;
    }
};