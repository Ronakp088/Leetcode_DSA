class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start^goal;
        int ans = 0;
        while(temp > 0){
            ans += temp%2;
            temp /= 2;
        }
        return ans;
    }
};