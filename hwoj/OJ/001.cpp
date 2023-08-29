/*
 * 银行插队
 * 输入描述：
 * 输入第一行是一个正整数 n，表示输入的序列中的事件数量。(1≤n≤500)
 * 接下来有 n 行，每行第一个字符为 a 或 p。
 * 当字符为 a 时，后面会有两个的正整数 num 和 x，表示到来的客户编号为 num，优先级为 x;
 * 当字符为 p 时，表示当前优先级最高的客户去办理业务。
 * 输出描述：
 * 输出包含若干行，对于每个 p，输出一行，仅包含一个正整数 num, 表示办理业务的客户编号。
 * 4
 * a 1 3
 * a 2 2
 * a 3 2
 * p
 * 输出 2
 */
#include<iostream>
#include<vector>

using namespace std;
// 去掉空格
vector<string> split_str(string str, string op) {
    vector<string> p;
    while(str.find(op) != string::npos) {
        int idx = str.find(op);
        p.push_back(str.substr(0, idx));
        str = str.substr(idx+1);
    }
    p.push_back(str);
    return p;
}
int main() {
    string cnt;
    getline(cin, cnt);
    int n = stoi(cnt);
    vector<vector<int>> v(6, vector<int>());
    for(int i = 0; i<n; i++) {
        string line;
        getline(cin ,line);
        vector<string> temp = split_str(line, " ");
        if(temp[0] == "a") {
            int x, y;
            x = stoi(temp[1]);
            y = stoi(temp[2]);
            v[y].push_back(x);
        }else {
            for(int j = 1; j <=5; j++) {
                if(v[j].size() != 0) {
                    cout << v[j][0] << endl;
                    v[j].erase(v[j].begin());
                    break;
                }
            }
        }
    }
    return 0;
}

