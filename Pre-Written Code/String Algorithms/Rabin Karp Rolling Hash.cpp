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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}