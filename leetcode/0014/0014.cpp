//分治
#include <iostream>
#include <vector>

using namespace std;

string findPrefix(string s1, string s2) {
    string s = "";
    for(int i = 0; i < min(s1.size(), s2.size()); i++) {
        if(s1[i] == s2[i]) {
            s += s1[i];
        } else {
            break;
        }
    }
    return s;
}

string split(vector<string> v, int l, int r) {
    if(l==r) {
        return v[l];
    }
    int mid = (l + r) / 2;
    string s1 = split(v, l, mid);
    string s2 = split(v, mid+1, r);
    return findPrefix(s1, s2);
}


int main() {
    string s;
    vector<string> v;
    while(cin >> s) {
        v.push_back(s);
        char ch = getchar();
        if(ch == '\n') break;
    }
    cout << split(v, 0, v.size()-1) << endl;
}

