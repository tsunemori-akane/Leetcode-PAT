//
// Created by cal on 2023/5/27.
//
/*
 * 按照身高体重排队
 * 输入
 * 4 （人数）
 * 100 100 120 130 （身高）
 * 40 30 60 50 （体重）
 * 输出身高由低到高，若相同按照体重排，若再相同按照原始序列编号排
 * 输出 2 1 3 4
 */

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> w(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
}
