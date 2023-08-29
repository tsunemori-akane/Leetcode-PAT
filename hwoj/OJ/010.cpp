//
// Created by cal on 2023/6/3.
//
/*
 * 输入数据 有多组，每组输入数据有两行
 * 6 7  （n和m，m代表发给小明牌上的数字）
 * 6 2 12 3 5 5 （n个数字，代表发的n张牌上的数字）
 * 若存在连续若干张牌之和可以整除 m 则输出1 否则输出 0
 */

#include<iostream>
#include<vector>

using namespace std;

int main () {
    int n, m;
    while(cin >> n >> m) {
        vector<int> ints(n);
        vector<int> mod(m, 0);
        for(int i = 0; i < n; i++) {
            cin >> ints[i];
        }
        bool isTrue = false;
        int preSum = 0;
        for(int i = 0; i < n; i++) {
            preSum += ints[i];
            preSum %= m;
            if(mod[preSum] != 0) {
                // 前面存在该余数，表示可以整除
                isTrue = true;
                break;
            }
            mod[preSum] ++;
        }
        cout << (isTrue ? 1 : 0) << endl;
    }
    return 0;
}