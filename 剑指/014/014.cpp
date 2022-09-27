//f(n) = max(f(i)*f(n-i))
class Solution {
public:
    int cuttingRope(int n) {
        if(n < 2) {
            return 0;
        }
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }
        vector<int> v(n + 1, 0);
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
        v[3] = 3;
        int max = 0;
        for (int i = 4; i <= n; i ++) {
            max = 0;
            for(int j = 0; j <= i/2; j++) {
                if(v[j]*v[i-j] > max) {
                    max = v[j]*v[i-j];
                }
                v[i] = max;
            }
        }
        return v[n];
    }

};
