class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n1 = jewels.size();
        int n2 = stones.size();
        int ans =0;
        for(int i =0;i<n1;i++){
            for(int j =0;j<n2;j++){
                if((int)(stones[j]) == (int)(jewels[i])) ans++;
            }
        }
        return ans;
    }
};