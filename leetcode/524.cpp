// s在dictionary中的字符串是有序的
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for(const string& e: dictionary) {
            if(ok(s,e)) {
                if(e.size() > res.size() ||  (e.size() == res.size() && e < res)) {
                    res = e;
                }
            }
        }
        return res;
    }

private:
    bool ok(const string& s, const string& e) {
        int cnt = 0;
        for(int i=0; i < s.size() && cnt < e.size(); i ++) {
            if(s[i] == e[cnt]) cnt ++;
        }
        return cnt == e.size();
    }
};
