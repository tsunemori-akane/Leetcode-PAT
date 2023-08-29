/*
 * 有N条线段，长度分别为 a[1] - a[n]
 * 现要求计算这N条线段最多可以组合成几个三角形
 * 每个线段只能使用一次，每个三角形三个线段
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

int getCount(int n, vector<int> v) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1, k = j + 1; j < n - 1 ;j ++) {
            while(k < n && v[i] + v[j] > v[k]) {
                k++;
            }
            cnt += k-j-1;
        }
    }
    return cnt;
}
int main() {
    int T;
    cin >> T;
    for(int p = 0; p < T; p++) {
        int N;
        cin >> N;
        vector<int> nums(N);
        for(int j = 0; j < N; j++) {
            cin >> nums[j];
        }
        sort(nums.begin(), nums.end(), [](int x, int y){return x < y;});
        cout << getCount(N, nums) << endl;
    }
}