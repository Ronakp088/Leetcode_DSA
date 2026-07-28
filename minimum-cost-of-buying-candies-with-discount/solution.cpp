class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n =cost.size();
        int ans=0;
        int flag =0;
        for(int i =n-1;i>=0;i--){
             if(flag == 2){
                flag = 0;
            }
            else {
            ans += cost[i];
            flag++;
            }
        }
        return ans;
    }
};