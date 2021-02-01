#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

int main() {
    int t; cin >> t; while(t--) {
        int n; cin >> n; v.resize(n);
        for (auto& x : v) { cin >> x; }

        vector<pair<int, int>> res;
        if (v[0][1] == v[1][0]) {
            if (v[0][1] == '0') {
                if (v[n - 1][n - 2] == '0') { res.push_back({ n - 1, n - 2 }); }
                if (v[n - 2][n - 1] == '0') { res.push_back({ n - 2, n - 1 }); }
            }
            else {
                if (v[n - 1][n - 2] == '1') { res.push_back({ n - 1, n - 2 }); }
                if (v[n - 2][n - 1] == '1') { res.push_back({ n - 2, n - 1 }); }
            }
        }
        else if (v[n - 1][n - 2] == v[n - 2][n - 1]) {
            if (v[n - 1][n - 2] == '0') {
                if (v[0][1] == '0') { res.push_back({ 0, 1 }); }
                if (v[1][0] == '0') { res.push_back({ 1, 0 }); }
            }
            else{
                if (v[0][1] == '1') { res.push_back({ 0, 1 }); }
                if (v[1][0] == '1') { res.push_back({ 1, 0 }); }
            }
        }
        else{
            res.push_back({ 0, 1 });
            if (v[n - 1][n - 2] == v[0][1]) { res.push_back({ n - 2, n - 1 }); }
            else { res.push_back({ n - 1, n - 2 }); }
        }
        cout << res.size() << '\n';
        for (auto& x : res) cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    }
    cin.ignore(2); return 0;
}