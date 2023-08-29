#include<iostream>
using namespace std;
int main() {
    int n, min = 101, max = -1, score;
    cin >> n;
    string st_name, st_num, max_name, min_name, max_num, min_num;
    
    for (int i = 0; i < n; i ++) {
        cin >> st_name >> st_num >> score;
        if (max < score){
            max = score;
            max_num = st_num;
            max_name = st_name;
        }
        if (min > score){
            min = score;
            min_num = st_num;
            min_name = st_name;
        }
    }
    cout << max_name << " " << max_num << endl << min_name << " " << min_num ;
}