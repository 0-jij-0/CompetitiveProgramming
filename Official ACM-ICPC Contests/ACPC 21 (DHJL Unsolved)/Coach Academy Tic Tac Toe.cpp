#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;

vector<string> v;

int res[3][3], G[3][3][3][3], full[3][3];
map<string, int> idx = { {"TL", 0}, {"TM", 1}, {"TR", 2}, {"ML", 3}, {"M", 4}, {"MR", 5}, {"BL", 6}, {"BM", 7}, {"BR", 8} };

int isWin(int i, int j){
    for(int k = 0; k < 3; k++){
        if(G[i][j][k][0] && G[i][j][k][0] == G[i][j][k][1] && G[i][j][k][1] == G[i][j][k][2]) return G[i][j][k][0];
        if(G[i][j][0][k] && G[i][j][0][k] == G[i][j][1][k] && G[i][j][1][k] == G[i][j][2][k]) return G[i][j][0][k];
    }
    if(G[i][j][0][0] && G[i][j][0][0] == G[i][j][1][1] && G[i][j][1][1] == G[i][j][2][2]) return G[i][j][0][0];
    if(G[i][j][0][2] && G[i][j][0][2] == G[i][j][1][1] && G[i][j][1][1] == G[i][j][2][0]) return G[i][j][0][2];
    return 0;
}

int main() {
    freopen("tictactoe.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; getline(cin, s);
    int n = stoi(s); v.resize(n);
    for(int i = 0; i < n; i++) getline(cin, v[i]);

    fill(res[0], res[0] + 9, 0);
    fill(G[0][0][0], G[0][0][0] + 81, 0);
    fill(full[0], full[0] + 9, 0);

    bool first = true; int last = 0;
    for(int k = 0; k < n; k++){
        stringstream ss(v[k]);
        string I; ss >> I; int i = idx[I];
        string J; ss >> J; int j = idx[J];
        int ii = i / 3, ij = i % 3, ji = j / 3, jj = j %3;
        if(first){
            first = false; full[ii][ij]++;
            G[ii][ij][ji][jj] = (k & 1 ? 1 : -1);
            last = j; continue;
        }

        if(full[last / 3][last % 3] != 9 && i != last){
            cout << "INVALID " << I << ' ' << J << '\n'; return 0;
        }
        if(G[ii][ij][ji][jj]){
            cout << "INVALID " << I << ' ' << J << '\n'; return 0;
        }

        G[ii][ij][ji][jj] = (k & 1 ? 1 : -1);
        if(!res[ii][ij]) res[ii][ij] = isWin(ii, ij);
        full[ii][ij]++; last = j;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << (res[i][j] ? (res[i][j] < 0 ? 'X' : 'O') : 'E') << "|\n"[j == 2];
        }
        if(i != 2){cout << "-----\n";}
    }
}
