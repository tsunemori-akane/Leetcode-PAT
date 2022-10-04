#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> res;
    string s;
    char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    void dfs(int x,int len){//x表示从左往右第x位，len表示总共len位；
        if(x==len){//终止条件,x从0-len-1位已经循环完了，现在是第len位了 
            res.push_back(s);//把之前创建的s添加到字符串数组res中 比如x=0 i=1 时 第一个添加的s="1"
            return;
        }
        int start= (x==0)?1:0;//第一位特殊处理 去除0从1开始
        for(int i=start;i<10;i++){
            s.push_back(num[i]);//循环第x位从0-9，比如1
            dfs(x+1,len);//循环第x+1位0-9，接上上一位，s.push_back(num[i]) 比如10 11 12 13..
            s.pop_back(); //把最后一位清除
            //否则s在for(int i=start;i<10;i++循环中比如i=1时 s.push_back会变成1 12 123 1234而不是1 2 3 4
        }
    }

public:
    vector<int> printNumbers(int n) {
        // 一次dfs添加i位的所有数字,比如i=3位是100-999,循环添加1-i
        for(int i = 1; i <= n; i++){
            dfs(0, i);
        }
        vector<int> ans;
        for(int i=0;i<res.size();i++){
            ans.push_back(stoi(res[i]));//stoi() 是string转int的函数 
        }
        return ans;
    }
};

int main() {
    Solution solution;
    solution.printNumbers(2);
}
