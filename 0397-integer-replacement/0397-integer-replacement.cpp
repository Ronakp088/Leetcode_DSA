class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        long long m = n;
        while(m != 1){
            if(m%2 == 0) m /= 2;
            else if((m-1)/2 == 1) m -= 1;
            else if(((m-1)/2)%2 == 0) m -= 1;
            else if((1LL*(m+1)/2)%2 == 0) m += 1;
            else m -= 1;
            cnt++;
        }
        return cnt;
    }
};