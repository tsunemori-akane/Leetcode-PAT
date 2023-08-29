/*
 * 称砝码
 * 对于每组测试数据：
 * 第一行：n — 砝码的种数(范围[1,10])
 * 第二行：m1 m2 m3 … mn — 每种砝码的重量(范围[1,2000])
 * 第三行：x1 x2 x3 …. xn — 每种砝码对应的数量(范围[1,10])
 * 现在要用这些砝码去称物体的重量，问能称出多少种不同重量
 */
#include <iostream>
#include <vector>

using namespace std;
vector<int> getResult(int n, vector<int>& weight, vector<int>& num) {
    int bag = 0;
    vector<int> newWeight;
    for(int i = 1; i<=n; i++) {
        bag += weight[i] * num[i];
        // 二进制优化 转换为01背包问题
        // 10 -> 1 2 4 3
        for(int j = 1; j <= num[i]; j <<= 1) {
            newWeight.push_back(weight[i]*j);
            num[i] -= j;
        }
        if(num[i] != 0) {
            newWeight.push_back(weight[i] * num[i]);
        }
    }
    vector<bool> dp(bag + 1, false);
    dp[0] = true;
    for(auto w: newWeight) {
        for(int j = bag; j>=w; j--) {
            if(dp[j-w]) dp[j] = true;
        }
    }
    vector<int> res;
    for(int i = 0; i < dp.size(); i++) {
        if(dp[i]) res.push_back(i);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> weight(n+1);
    vector<int> num(n+1);
    for (int i =1; i<=n; i++) {
        cin >> weight[i];
    }
    for (int i =1; i<=n; i++) {
        cin >> num[i];
    }
    vector<int> res = getResult(n, weight, num);
    for(auto b: res) {
        cout << b << " ";
    }
}