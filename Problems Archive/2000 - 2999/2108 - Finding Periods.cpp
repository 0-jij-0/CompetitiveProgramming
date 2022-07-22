#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> zFunction(const string &s) {
    int n = (int)s.size(); vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s; int n = s.size();
    vector<int> Z = zFunction(s);

    for (int i = 0; i < n; i++)
        if (i + Z[i] >= n) cout << i << ' ';
    cout << n << '\n';
}