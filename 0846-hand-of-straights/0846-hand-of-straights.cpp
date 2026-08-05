class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int> pq;
        int n = hand.size();
        if (n < groupSize || n % groupSize != 0)
            return false;
        for (int i = 0; i < n; i++) {
            pq.push(hand[i]);
        }
        stack<int> st;
        while (!pq.empty()) {
            int temp = pq.top();
            pq.pop();
            for (int i = 1; i <= groupSize - 1; i++) {
                if (temp - pq.top() != 1) {
                    while (temp - pq.top() != 1) {
                        st.push(pq.top());
                        pq.pop();
                        if (pq.empty())
                            return false;
                    }
                    temp = pq.top();
                    pq.pop();
                    while (!st.empty()) {
                        pq.push(st.top());
                        st.pop();
                    }
                } else {
                    temp = pq.top();
                    pq.pop();
                }
            }
        }
        return true;
    }
};