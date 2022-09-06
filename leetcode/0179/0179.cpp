//对于两个数a和b，如果ab > ba，那么就把a放在b前。反之将b置前
#include<iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int &a, int &b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);

    return s1 > s2;
}
int main() {
    int num;
    vector<int> v;
    while(cin >> num) {
        v.push_back(num);
        char ch = getchar();
        if(ch == '\n') break;
    }
    sort(v.begin(), v.end(), cmp);
    string res;
    for (auto e : v) {
        res += to_string(e);
    }
    if(res[0] == '0') {
        res = "0";
    }
    cout << res << endl;
}
