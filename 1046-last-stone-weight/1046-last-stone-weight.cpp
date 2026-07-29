class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
     //   int check = pq.size();
        while(pq.size() > 1){
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if(s2 < s1){
                pq.push(s1-s2);
            }
            else if(s2 == s1 && pq.empty()){
                return 0;
            }
        }
        return pq.top();
    }
};