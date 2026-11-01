class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int t = 0;t<amount+1;t++){
            if(t%coins[0] == 0) prev[t] = t/coins[0];
            else prev[t] = 1e9;
        }
        for(int i =1;i<n;i++){
            for(int j =0;j<amount+1;j++){
                int notTake = 0 + prev[j];
                int take = INT_MAX;
                if(j - coins[i] >= 0) take = 1 + curr[j-coins[i]];
                curr[j] =  min(take,notTake);
            }
            prev = curr;
        }
        if(prev[amount] >= 1e9) return -1;
        return prev[amount];
    }
};