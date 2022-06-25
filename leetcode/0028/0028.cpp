#include <iostream>

using namespace std;

bool compare(string a, string b) {
    for(int i=0, j=b.size(); j>=i; i++, j--) {
        if(a[i]!=b[i] || a[j]!=b[j]) return false;
    }
    return true;
}
int main () {
    string haystack, needle;
    while(cin >> haystack >> needle) {
        if(needle.size() == 0 || needle.size() > haystack.size()) return -1;
        for(int i = 0, j = needle.size()-1; j < haystack.size(); i++, j++) {
            if(needle[0] == haystack[i] && needle[needle.size()-1] == haystack[j]) {
                if(needle.size() == 1) return i;
                if(compare(haystack.substr(i+1,needle.size()-2), needle.substr(1,needle.size()-2))) {
                    return i;
                }
            }
        }
        return -1;
    }
}

