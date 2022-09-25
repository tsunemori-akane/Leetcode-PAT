//尾递归，正常递归会超时
class Solution {
public:
    int fib(int n) {
        if(n <= 1) {
            return n;
        }
        return myFib(n, 0 ,1);
    }

    int myFib(int n, int pre1, int pre2) {
        if(n == 1) return pre2;
        return myFib(n-1, pre2, (pre1 + pre2) % 1000000007);
    }
};
