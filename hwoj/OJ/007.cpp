/*
 * 输入第一行为一维整形数组M, 数组长度小于100， 数组元素记录单个商品价格， 单个商品价格小于1000
 * 输入第二行为购买资金的额度R, R 小于 100000
 * 条件：购买三件，且尽可能的花完资金
 * 输出满足条件的最大花费额度
 */

#include<iostream>
#include<vector>

using namespace std;

vector<int> split_str(string str) {
    vector<int> v;
    while(str.find(" ") != string::npos) {
        int index = str.find(" ");
        v.push_back(stoi(str.substr(0, index)));
        str = str.substr(index+1);
    }
    return v;
}

int main() {
    string line;
    getline(cin, line);
    vector<int> v = split_str(line);
    vector<int> res;
    int maxNum;
    cin >> num;
    if(v.size() < 3) return 0;
    sort(v.begin(), v.end());
    // 将每一个可能数值加入数组
    int left, right;
    for(int i = 0; i < v.size() -2; i++) {
        left = i + 1;
        fight = len -1;
        while(left < right) {
            if(v[left] + v[right] + v[i] <= maxNum) {
                res.push_back(v[left] + v[right] + v[i]);
                left ++;
            } else {
                right --;
            }
        }
    }
    sort(res.begin(), res.end());
}