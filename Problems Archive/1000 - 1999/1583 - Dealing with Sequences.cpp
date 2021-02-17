#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int SVSZ = 1000 * 1000 + 1;

int spf[SVSZ];

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

vector<int> getDivisors(int x) {
	vector<int> v; while (x > 1) {
		int d = spf[x]; v.push_back(d);
		while (x % d == 0) { x /= d; }
	}
	return move(v);
}

vector<int> v;
vector<vector<int>> pf;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	buildSieve();

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); pf.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i]; pf[i] = getDivisors(v[i]);
		}

		set<int> cur;
		int i = 0, j = 0, res = 0;
		while (j != n) {
			for(int k = 0; k < (int)pf[j].size(); k++) {
				if (!cur.count(pf[j][k])) { cur.insert(pf[j][k]); continue; }
				for (auto& y : pf[i]) cur.erase(y); i++; k--;
			}
			res = max(res, j - i + 1); j++;
		}

		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}