class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //int mod = 1000000000 + 7;
        vector<unsigned int> prev(amount+1,0), curr(amount+1,0);
        for(int i =0;i<amount+1;i++){
            prev[i] = (i%coins[0] == 0);
        }
        for(int i =1;i<n;i++){
            for(int j = 0;j<amount+1;j++){
                unsigned int nottake = prev[j];
                unsigned int take = 0;
                if( j >= coins[i]) take = curr[j - coins[i]];
                curr[j] =  (take + nottake);
            }
            prev = curr;
        }
        return prev[amount];
    }
};