class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        long long v = x;
        if(x < 0){
            flag = -1;
            v = abs(v);
        }
        long long temp = 0;
        while(v>0){
            temp = temp*10 + v%10;
            v /= 10;
        if(temp > INT_MAX ) return 0;
        }
        long long check = flag*temp;
        if(temp > INT_MAX || temp < INT_MIN) return 0;
        return check ;

    }
};