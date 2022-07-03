#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string s, temp;
    int count = 0;
    unordered_map<char, int> m;
    getline(cin, s);

    for(int i=0, j=0; j<s.size() && i<s.size();) {
        if(m[s[j]] > 0) {
            m[s[i]] -= 1;
            ++i;
        } else {
            m[s[j]] = 1;
            count = temp.size();
            temp = count >= j-i+1 ? temp : s.substr(i, j-i+1);
            ++j;
        }
    }
    cout << temp << endl;
    return 0;
}
