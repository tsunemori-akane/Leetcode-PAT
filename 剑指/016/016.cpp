class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0) return 1;
        if(x == 0) return 0;
        
        if(n < 0) {
            x = 1/x;
            n = -n;
        }
        /*
        负数右移时，要保证移位后还是一个负数，最高位会设为1，如果一直做右移运算最终n变成0xFFFFFFFF，递归无法终止
        */
        double res = myPow(x, n>>1);
        res *= res;
        // 奇数
        if(n & 0x1 == 1) {
            res *= x;
        }
        return res;
    }
};
