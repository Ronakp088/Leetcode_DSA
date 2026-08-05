class Solution {
public:
    int leastInterval(vector<char>& task, int n) {
        int m = task.size();
        vector<int> freq(26,0);
        priority_queue<int> pq;
        for(int i =0;i<m;i++){
            freq[task[i]-'A']++;
        }
        for(int i =0;i<26;i++){
            if(freq[i] >0) pq.push(freq[i]);
        }
        int  f = pq.top();
        int gap = (f-1)*n;
        pq.pop();
        while(!pq.empty()){
            gap -= min(f-1,pq.top());
            pq.pop();
        }
        return task.size() + max(0,gap);
    }
};