class Solution {
public:
    int smallestNumber(int n, int t) {
        while (n>0){
            int k=n;
            int c=1;
            while (k>0){
                int d = k%10;
                k=k/10;
                c=c*d;
            }
            if (c%t==0){
                return n;
            }
            else {
                n++;
            }
        }
        return -1;
    }
};