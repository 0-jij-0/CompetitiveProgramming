#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll dp[65][2][2][2]; string A, B;

bool check00(bool g, bool x, bool y, char a, char b) {
	if (!x) { return true; }
	return a == '0';
}

bool check01(bool g, bool x, bool y, char a, char b) {
	if (x && y) { return a == '0' && b == '1'; }
	if (x) { return a == '0'; }
	if (y) { return b == '1'; }
	return true;
}

bool check10(bool g, bool x, bool y, char a, char b) {
	return g;
}

ll count(int i, bool g, bool x, bool y) {
	if (i == 65) { return 1; }
	if (dp[i][g][x][y] != -1) { return dp[i][g][x][y]; }

	ll res = 0;
	if (check00(g, x, y, A[i], B[i])) {
		res = (res + count(i + 1, g, x && A[i] == '0', y && B[i] == '0')) % mod;
	}
	if (check01(g, x, y, A[i], B[i])) {
		res = (res + count(i + 1, true, x && A[i] == '0', y && B[i] == '1')) % mod;
	}
	if (check10(g, x, y, A[i], B[i])) {
		res = (res + count(i + 1, true, x && A[i] == '1', y && B[i] == '0')) % mod;
	}


	return dp[i][g][x][y] = res;
}

string toString(ll a) {
	string res = "";
	while (a) { res.push_back((a & 1) + '0'); a >>= 1; }
	while (res.size() != 65) { res.push_back('0'); }
	reverse(res.begin(), res.end()); return move(res);
}

int main() {
	freopen("or.in", "r", stdin);
	int t; cin >> t; while (t--) {
		ll a, b; cin >> a >> b;
		A = toString(a); B = toString(b);
		fill(dp[0][0][0], dp[0][0][0] + 65 * 8, -1);
		cout << (2 * count(0, false, true, true) - (a == 0) + mod) % mod << '\n';
	}
	cin.ignore(2); return 0;
}