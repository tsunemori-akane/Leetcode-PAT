/*
 *  在一个狭小的路口，每秒只能通过一辆车，假好车辆的颜色只有 3 种，找出 N 秒内经过的最多颜色的车辆数量。
 *  三种颜色编号为0,1,2
 *  输入描述：
 *  第一行输入通过车辆颜色信息 [0,1,1,2] 表示四秒
 *  第二行输入统计时间窗 3，整型，单位秒
 *  输出2
 */

#include <iostream>
#include <vector>
using namespace std;
//去掉空格
vector<int> split_str(string str) {
    vector<int> v;
    while(str.find(" ") != string::npos) {
        int index = str.find(" ");
        v.push_back(stoi(str.substr(0, index)));
        str = str.substr(index + 1);
    }
    return v;
}
int main() {
    string line;
    getline(cin, line);
    vector<int> v = split_str(line);
    int n;
    cin >> n;
    int count_car[3] = {0, 0, 0};
    for(int i=0; i<n; i++) {
        count_car[v[i]] +=1;
    }
    // 开始滑动窗口
    int res = max({count_car[0], count_car[1], count_car[2]});
    for(int i = n; i < v.size(); i++) {
        // 计算窗口中 res
    }
}