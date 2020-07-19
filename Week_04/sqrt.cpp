class Solution {
    int s;
public:
    int mySqrt(int x) {
        s = x;
        if ( x == 0 ) return 0;
        return (int)sqrts(x);
    }

    double sqrts( double x) {
        double res = ( x + s / x ) / 2;
        if ( res == x ) return x;
        else return sqrts(res);
    }
};