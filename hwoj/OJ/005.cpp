/*
 * 在一个密码本中，每一页都有一个由26个小写字母组成的若干位密码，每一页的密码不同，需要从这个密码本中寻找这样一个最长的密码，
 * 从它的末尾开始依次去掉一位得到的新密码也在密码本中存在。
 * 请输出符合要求的密码，如果有多个符合要求的密码，则返回字典序最大的密码。
 * 若没有符合要求的密码，则返回空字符串。示例如下
 * 输入：b ereddred bw bww bwwl bwwlm bwwln
 * 输出：bwwl
 */

# include<iostream>
# include<vector>

using namespace std;
int main() {
    string str;
    vector<string> v;
    while(cin >> str) {
        if(getchar() == '\n') break;
        v.push_back(str);
    }

}