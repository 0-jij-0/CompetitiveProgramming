#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

vector<set<int>> v; set<int> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i = 1; i <= k; i++) st.insert(i);
	v.resize(n, st);
	
	for(int i = 1; i <= k; i++) {
		char c; int x; cin >> c >> x; x--;
		if (!v[x].count(i)) { v[x].clear(); continue; }
		if (c == 'L') {
			v[x].clear(); v[x].insert(i);
			for (int j = 0; j < x; j++) v[j].erase(i);
		}
		if (c == 'R') {
			v[x].clear(); v[x].insert(i);
			for (int j = n - 1; j > x; j--) v[j].erase(i);
		}
	}

	ll res = 1; for (auto& x : v) res = (res * x.size()) % mod;
	cout << res << '\n'; cin.ignore(2); return 0;
}