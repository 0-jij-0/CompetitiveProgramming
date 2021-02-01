#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		vector<pair<ll, int>> G;
		ll res = *max_element(v.begin(), v.end());
		for (int i = n - 1; i >= 0; i--) {
			vector<pair<ll, int>> temp(1, { v[i], 1 }); 
			int m = (int)G.size();
			for (int j = 0; j < m; j++) {
				ll g = gcd(G[j].first, v[i]);
				if (g == temp.back().first) { temp.back().second = G[j].second + 1; }
				else { temp.emplace_back(g, G[j].second + 1); }
				res = max(res, temp.back().first * temp.back().second);
			}
			G = move(temp);
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}