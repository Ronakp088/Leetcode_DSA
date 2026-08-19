class Solution {
public:
    long long nCr(int n, int r) {
    if (r > n) return 0;

    r = min(r, n - r);

    long long res = 1;

    for (int i = 0; i < r; i++) {
        res = res * (n - i) / (i + 1);
    }

    return res;
}

    int uniquePaths(int m, int n) {
        int t = m + n - 2;
        int r = m - 1;

        return (int)nCr(t, r);
    }
};
// down move no = m-1
// right move no = n-1
/*
it means  total moves = m+n-2
now now i want to take like m+n-2 C m-1 
means taking any random m-1 places to take down 

m= 3
n=7
total = 3+7-2=8
now 8C2  is 8*7/2= 28 sahi hai 
now 
m=3
n=2
total 3+2-2=3
3C1 =3 sahi hai 
 */