#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
const int SVSZ = 2 * 1000 * 100 + 1;
const ll mod = 1000 * 1000 * 1000 + 7;

int spf[SVSZ];

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

struct pqObj {
	int i; int p; pqObj() {}
	pqObj(int _i, int _p) : i(_i), p(_p) {}
	bool operator < (const pqObj& rhs) const { return p > rhs.p; }
};

vector<map<int, int>> pf;
map<int, priority_queue<pqObj>> minP;
map<int, int> minPC;
vector<int> v;

map<int, int> fact(int x) {
	map<int, int> res;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		while (x % d == 0) { x /= d; cnt++; }
		res[d] = cnt;
	}
	return move(res);
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll power(int x, int n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q; 
	buildSieve(); v.resize(n); pf.resize(n);

	ll res = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i]; res = gcd(res, v[i]); 
		pf[i] = fact(v[i]); for (auto& x : pf[i]) {
			minP[x.first].push(pqObj(i, x.second));
			minPC[x.first]++;
		}
	}

	while (q--) {
		int i, x; cin >> i >> x; i--;
		map<int, int> curM = fact(x);
		for (auto& x : curM) {
			if (!pf[i].count(x.first)) {
				minPC[x.first]++; 
				if (minPC[x.first] == n)
					minP[x.first].push(pqObj(i, 0));
			}

			pf[i][x.first] += x.second;
			minP[x.first].push(pqObj(i, pf[i][x.first]));

			ll prev = minP[x.first].top().p;
			while (true) {
				pqObj cur = minP[x.first].top();
				if (cur.p != pf[cur.i][x.first]) { minP[x.first].pop(); continue; }
				break;
			}
			ll cur = minP[x.first].top().p;
			if (minPC[x.first] == n) { res = (res * power(x.first, cur - prev)) % mod; }
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}