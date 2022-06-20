//执行用时：20 ms, 在所有 C++ 提交中击败了23.09%的用户
//内存消耗：8 MB, 在所有 C++ 提交中击败了24.51%的用户
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> dic;
    string s;
    int res = 0;
    getline(cin, s);
    dic = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    for(int i=0; i<s.size(); i++) {
        if(i+1 <= s.size()-1){
            if(dic[s[i+1]] - dic[s[i]] > 0) {
                res += dic[s[i+1]] - dic[s[i]];
                i += 1;
            } else if(dic[s[i+1]] - dic[s[i]] <= 0) {
                res += dic[s[i]];
            }
        } else {
            res += dic[s[i]];
        }
    }
    cout << res << endl;
}
