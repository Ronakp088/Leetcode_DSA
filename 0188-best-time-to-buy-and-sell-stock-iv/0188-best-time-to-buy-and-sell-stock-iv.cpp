class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int>buy(k+1, -100000);
        vector<int>sell(k+1);

        sell[0]=0;
        for(auto p: prices) {
            for(int i=1; i<=k; i++){
                sell[i]=max(sell[i-1], sell[i]);
                sell[i] = max(buy[i]+p, sell[i]);
                buy[i] = max(sell[i-1]-p, buy[i]);
            }
        }
        return sell[k];
    }
};