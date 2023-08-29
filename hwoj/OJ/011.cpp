//
// Created by cal on 2023/6/3.
//
/*
 * 有N个运动员，ID为 0～N-1
 * 输入一组整数代表运动员实力，0号和1号比赛，2号和3号比赛，类推，实力等同时ID小的情况获胜，轮空直接进入下一轮。
 * 输出获胜者ID
 */

#include<iostream>
#include<vector>

using namespace std;

struct Player {
    int id;
    long long power;
};

pair<int, int> findChampion(vector<long long>& powers) {
    int n = powers.size();
    vector<Player> players(n);

    for(int i = 0; i < n; i ++) {
        players[i].id = i;
        players[i].power = powers[i];
    }
    while(n > 2) {
        int newN = (n + 1) / 2;
        for(int i = 0; i < newN; i++) {
            int j = i * 2;
            if(players[j].power > players[j + 1].power) {
                players[i] = players[j];
            } else if(players[j].power < players[j + 1].power) {
                players[i] = players[j + 1];
            } else {
                // min(players[j], players[j+1], comPlayer)
                players[i] = players[j].id < players[j+1].id ? players[j] : players[j+1];
            }
        }
        n = newN;
    }
    if(players[0].power > players[1].power) {
        return make_pair(players[0].id, players[1].id);
    } else {
        return make_pair(players[1].id, players[0].id);
    }
}
vector<long long> split_str(string str, string op) {
    vector<long long> p;
    while(str.find(op) != string::npos) {
        int idx = str.find(op);
        p.push_back(stoi(str.substr(0, idx)));
        str = str.substr(idx+1);
    }
    p.push_back(stoi(str));
    return p;
}

int main() {
    string line;
    getline(cin, line);
    vector<long long> v = split_str(line, " ");
    pair<int, int> res = findChampion(v);
    cout << res.first +1 << " " << res.second+1 << endl;
}