/*
 * 第 1 个字符串：R
 * 第 2 个字符串：BR
 * 第 3 个字符串：RBBR
 * 第 4 个字符串：BRRBRBBR
 * 第 5 个字符串：RBBRBRRBBRRBRBBR
 * 相信你已经发现规律了，没错！
 * 就是第i个字符串 = 第i-1号字符串的取反 + 第i-1号字符串。
 * 取反即(R->B, B->R);
 * 现在告诉你 n 和 k ，让你求得第n个字符串的第k个字符是多少。
 * (k的编号从0开始)
 */

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

char find (int n ,int k) {
    if(n == 1) {
        return 'R';
    }
    long len = pow(2, n-1);
    if(k >= len/2) {
        return find(n-1, k - len/2);
    } else {
        return find(n - 1, k) == 'R' ? 'B' : 'R';
    }
}

int main() {
    int t;
    cin >> t;
    vector<vector<long>> input;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<long> v;
        v.push_back(n);
        v.push_back(k);
        input.push_back(v);
    }
    for(int i = 0; i < t; i++) {
        long n = input[i][0];
        long k = input[i][1];
        cout << find(n, k) << endl;
    }
}