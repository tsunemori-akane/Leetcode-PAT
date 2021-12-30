#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 1, r = x;
        while(l <= r) {
            int mid = l + (r-l)/2;
            int sqrt = x/mid;
            if (sqrt < mid) {
                r = mid - 1;
            } else if (sqrt > mid) {
                l = mid + 1;
            } else {
                return sqrt;
            }
        }
        return r;
    }
};

int main() {

    cout << Solution().mySqrt(255) << endl;
    system( "PAUSE ");
    return 0;
}
