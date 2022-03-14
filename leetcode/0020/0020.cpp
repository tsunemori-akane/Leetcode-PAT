#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

class Solution {
  public: 
  bool isValid(string s) {
    if(s[0] == '}' || s[0] == ')' || s[0] == ']') {
      return false;
    }
    
    stack<char> x;
    x.push(s[0]);
    for(int i = 1; i < s.length(); ++i) {
      if(!x.empty()) {
        string str;
        if( str + x.top() + s[i] == "{}" || str + x.top() + s[i] == "[]" || str + x.top() + s[i] == "()") {
          x.pop();
          cout << x.top() << endl;
        } else {
          x.push(s[i]);
        }
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
