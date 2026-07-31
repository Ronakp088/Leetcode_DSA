class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> arr(26);
        priority_queue<int> pq;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            arr[word[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                pq.push(arr[i]);
            }
        }
        int j = 0;
        while (!pq.empty()) {
            ans += pq.top() * (j / 8 + 1);
            j++;
            pq.pop();
        }
        return ans;
    }
};