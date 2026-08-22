class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0;
        int product = 1;
        int g = n;
        while(n>=1){
            int t = n%10;
            sum += t;
            product *= t;
            n /= 10;
        }
        return g%(sum+product) == 0 ;
    }
};