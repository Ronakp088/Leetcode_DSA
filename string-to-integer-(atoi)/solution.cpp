class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0) return 0;
        int index = 0;
        int p =0;
        long long ans =0;
        while(s[index] == ' '){
            index++;
        }
        if(s[index] == '-') {
            p =1;
            index++;
        }
        else if(s[index] == '+') index++; 
        while(index<s.size() && s[index] >='0' && s[index] <='9'){
         if(ans > INT_MAX) return p ? INT_MIN : INT_MAX; 
         ans  = ans*10 + (s[index] -'0');
         index++;
        }
           if(p){
            if((ans*-1) < INT_MIN) return INT_MIN;
            else return (ans) * -1;
           } 
        
        if(ans >INT_MAX) return INT_MAX;
        return ans; 
    }
};