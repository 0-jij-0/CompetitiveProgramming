#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
typedef long long ll;

int dp[1000001];

int findMex(unordered_set<int>& m){
    int res = 0;
    while(m.count(res)){ res++; }
    return res;
}

int main() {
    freopen("game.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dp[0] = 0;
    for(int x = 1; x <= 1000000; x++){
        string s = to_string(x);
        vector<int> zeroPos;
        unordered_set<int> nextMoves;
        for(int i = 0; i < s.size(); i++)
            if (s[i] == '0') zeroPos.push_back(i);

        int n = s.size(), m = zeroPos.size();
        for(int i = 0; i < (1<<m); i++){
            vector<int> newNums;
            int zeroID = 0, curNum = 0;

            for(int j = 0; j < n; j++){
                if (zeroID < zeroPos.size() && zeroPos[zeroID] == j){
                    if ((i >> zeroID) & 1) {
                        if (curNum != 0) { newNums.push_back(curNum); }
                        curNum = 0; zeroID++;
                    }
                    else{ zeroID++; curNum *= 10; }
                }
                else{ curNum *= 10; curNum += (s[j] - '0'); }
            }
            if (curNum != 0){ newNums.push_back(curNum); }

            int allXOR = 0; for(auto &c : newNums){ allXOR ^= dp[c]; }
            for(int j = 0; j < newNums.size(); j++){
                int curXOR = allXOR ^ dp[newNums[j]];
                for(int k = 1; k <= 3; k++){
                    if (k > newNums[j]) { continue; }
                    nextMoves.insert(curXOR ^ dp[newNums[j] - k]);
                }
            }
        }

        dp[x] = findMex(nextMoves);
    }

    int t; cin >> t; while(t--){
        int x; cin >> x;
        cout << (dp[x] ? "First" : "Second") << '\n';
    }
}