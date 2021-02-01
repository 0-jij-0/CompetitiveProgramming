#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int HASH1[21][1000001];
int HASH2[21][1000001];
int powX[1000001];
int logb2[1000001];
const ll mod = 1000000007;
const ll x = 998244353;

void fillPowX() { powX[0] = 1; for (int i = 1; i <= 1000000; i++) { powX[i] = (x * powX[i - 1]) % mod; } }

void fillLog() {
	logb2[1] = 0; int i = 2; memset(logb2, -1ll, sizeof(logb2));
	for (; i <= 1000000; i <<= 1) logb2[i] = logb2[i >> 1] + 1;
	i >>= 1; int prev = logb2[i] + 1;
	for (int i = 1000000; i >= 0; i--)
		if (logb2[i] != -1) { prev = logb2[i]; }
		else { logb2[i] = prev; }
}

ll rollHash(const string &s, int i, int k, ll &h) {
	ll dec = ((ll)s[i - k] * (ll)powX[k - 1]) % mod;
	h = (h - dec + mod) % mod;
	h *= x; h %= mod; h += s[i]; return h;
}

void fillHash(int HASH[21][1000001], const string &s) {
	int n = (int)s.size();
	for (int i = 0; i < 25; i++) {
		int len = 1 << i;
		if (len > n) { return; }
		ll h = 0;
		for (int j = 0; j < len; j++) {
			h *= x; h += s[j]; h %= mod;
		}
		HASH[i][0] = h;
		for (int j = 1; j <= n - len; j++)
			HASH[i][j] = rollHash(s, j + len - 1, len, h);
	}
}

string s, pref, suf;

bool checkPal(int i, int j) {
	while (i < j) if (s[i++] != s[j--]) return false;
	return true;
}

int prefPalLen(int i, int j) {
	if (i >= j) { return i == j; }
	int n = (int)s.size();
	for (int k = j; k >= i; k--) {
		if ((2 * (k - i + 1) - 1) > j - i + 1) { continue; }
		int ret = -1;

		//EVEN
		int l1 = i, r1 = k, l2 = k + 1, r2 = k + (k - i + 1);
		int len = logb2[r1 - l1 + 1]; bool b = r2 <= j;
		if (b && HASH1[len][l1] != HASH2[len][n - r2 - 1]) { b = false; }
		if (b && HASH2[len][n - r1 - 1] != HASH1[len][l2]) { b = false; }
		if (b && checkPal(l1, r2)) { return 2 * (k - i + 1); }

		//ODD
		l1 = i, r1 = k, l2 = k, r2 = k + (k - i);
		len = logb2[r1 - l1 + 1]; b = true;
		if (HASH1[len][l1] != HASH2[len][n - r2 - 1]) { b = false; }
		if (HASH2[len][n - r1 - 1] != HASH1[len][l2]) { b = false; }
		if (b && checkPal(l1, r2)) { return 2 * (k - i + 1) - 1; }
	}
	return 1;
}

int sufPalLen(int i, int j) {
	if (i >= j) { return i == j; }
	int n = (int)s.size();
	for (int k = i; k <= j; k++) {
		if (2 * (j - k + 1) - 1 > j - i + 1) { continue; }
		int ret = -1;

		//EVEN
		int l1 = k - 1 - (j - k), r1 = k - 1, l2 = k, r2 = j;
		int len = logb2[r1 - l1 + 1]; bool b = l1 >= i;
		if (b && HASH1[len][l1] != HASH2[len][n - r2 - 1]) { b = false; }
		if (b && HASH2[len][n - r1 - 1] != HASH1[len][l2]) { b = false; }
		if (b && checkPal(l1, r2)) { return 2 * (j - k + 1); }

		//ODD
		l1 = k - (j - k), r1 = k, l2 = k, r2 = j;
		len = logb2[r1 - l1 + 1]; b = true;
		if (HASH1[len][l1] != HASH2[len][n - r2 - 1]) { b = false; }
		if (HASH2[len][n - r1 - 1] != HASH1[len][l2]) { b = false; }
		if (b && checkPal(l1, r2)) { return 2 * (j - k + 1) - 1; }
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; fillLog(); fillPowX();
	while (t--) {
		pref.clear(); suf.clear();
		cin >> s; int n = (int)s.size();

		fillHash(HASH1, s);	reverse(s.begin(), s.end());
		fillHash(HASH2, s);	reverse(s.begin(), s.end());

		int i = 0, j = n - 1;
		while (i < j && s[i] == s[j]) { pref.push_back(s[i]); suf.push_back(s[j]); i++; j--; }
		reverse(suf.begin(), suf.end());

		int pl = prefPalLen(i, j), sl = sufPalLen(i, j);
		if (pl > sl) { pref += s.substr(i, pl); }
		else { suf = s.substr(j - sl + 1, sl) + suf; }
		cout << pref + suf << endl;
	}
	cin.ignore(2); return 0;
}