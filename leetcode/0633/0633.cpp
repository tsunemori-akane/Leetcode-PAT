class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned int l = 0, r = (unsigned int) sqrt(c);
        while(l <= r) {
            unsigned int res = l*l + r*r;
            if(res < c) {
                l++;
            }
            else if(res > c) {
                r--;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
