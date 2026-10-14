class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        ans.reserve(num);
        if(sum > 9*num) return "";
        int t =0;
        while(t < num){
            if(sum == 0){
                ans += '0';
            }
            else if( sum > 0 && sum < 9){
                ans += char('0' + sum);
                sum  = 0;
            }
            else{
                ans += '9';
                sum -= 9;
            }
            t++;
        }
        return ans;

    }
};