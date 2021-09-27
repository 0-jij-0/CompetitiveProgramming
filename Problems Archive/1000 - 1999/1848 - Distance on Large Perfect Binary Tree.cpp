#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll power[2000001];

inline ll p(int x) { return x < 0 ? 0 : power[x]; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	power[0] = 1; for (int i = 1; i <= 2000000; i++)
		power[i] = (power[i - 1] << 1) % mod;

	int n, d; cin >> n >> d;

	int level = 0; ll num = 1, res = 0;
	while (level < n) {
		ll maxDepth = n - 1 - level; ll one = 0; ll D = d - 2;
		if (maxDepth >= d) { one = (p(d) * num) % mod; }
		ll y = maxDepth - 1;
		
		ll cont = (y >= D ? D + 1 : max(0ll, y - (D - y) + 1));
		cont = (cont * p(D)) % mod;	cont = (cont * num) % mod;
		res = (res + cont + one) % mod;
		level++; num = (num << 1) % mod;
	}

	cout << (res << 1) % mod << '\n';
	cin.ignore(2); return 0;
}