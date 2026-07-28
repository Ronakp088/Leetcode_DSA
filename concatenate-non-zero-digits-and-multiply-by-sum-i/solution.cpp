class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum =0;
        stack<int> st;
        while(n>=1){
            int temp = n%10;
            if(temp != 0){
                sum += temp;
                st.push(temp);
            }
            n /= 10;
        }
        long long  ans =0;
        while(!st.empty()){
            ans = ans*10 + st.top();
            st.pop();
        }
        return ans*sum;
    }
};