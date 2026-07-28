class Solution {
public:
    bool checkGoodInteger(int n) {
        long long temp = n;
        long long digiSum =0;
        long long  squareSum =0;
        while(temp>0){
            int m = temp%10;
            digiSum += m;
            squareSum +=  m*m ;
            temp /= 10 ;
        }
        if((squareSum - digiSum) >= 50) return true;
        return false;
    }
};