#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s[0] == '}' || s[0] == ')' || s[0] == ']') {
            return false;
        }
        stack<char> x;
        for(int i = 0; i < s.length(); ++i) {
            if(!x.empty()) {
                string str;
                if( str + x.top() + s[i] == "{}" || str + x.top() + s[i] == "[]" || str + x.top() + s[i] == "()") {
                    x.pop();
                } else {
                    x.push(s[i]);
                }
            } else {
                x.push(s[i]);
            }
        }
        if(x.empty()) return true ;
        else return false;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {
  printBool(Solution().isValid("(){}}{"));
  system("PAUSE");
  return 0;
}
