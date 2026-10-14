class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans  = "";
        if(sum > 9*num) return "";
        int t =0;
        while(t < num){
            if(sum == 0){
                ans += to_string(sum);
            }
            else if( sum > 0 && sum < 9){
                ans += to_string(sum);
                sum  = 0;
            } 
            else{
                ans += to_string(9);
                sum -= 9;
            }
            t++;
        }
        return ans;
 
    }
};