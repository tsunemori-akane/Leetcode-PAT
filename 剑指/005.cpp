// 先计算空格数量，再给原字符串扩容，然后双指针倒序遍历
#include<iostream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int space = 0;
    int len = s.size()-1;
    for(auto e : s) {
        if(e == ' ') {
            space+=1;
        }
    }
    s.resize(s.size() + 2*space);
    for(int i = s.size()-1, j = len; i >= 0;) {
        if(s[i] == s[j] && s[j] != ' ') {
            --i;
            --j;
        } else if(s[j] == ' ') {
            s[i - 2] = '%';
            s[i - 1] = '2';
            s[i] = '0';
            i -= 3;
            --j;
        } else {
            s[i] = s[j];
            --i;
            --j;
        }
    }
    cout << s << endl;
    return 0;
}
