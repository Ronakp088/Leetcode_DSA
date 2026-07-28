class Solution {
public: 
    long double calcPosi(double x, long n){
    if(n == 0) return 1.0;
    if(n == 1) return x;
    long double half = calcPosi(x, n/2);
    if(n % 2 == 0) return half * half;
    else return half * half * x;
}
    long double calcNeg(double x,int n){
        long double temp = calcPosi(x,n);

        return 1/temp;
    }
    long double myPow(double x, int n){
        if(n == 0) return 1.0;
        else if( n > 0 ) return calcPosi(x,n);
        else return calcNeg(x,n);
        return 0;
    }
};